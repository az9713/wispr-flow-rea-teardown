# Development Journey — "flowlite": reverse engineering Wispr Flow with REA, then rebuilding it

**Date:** 2026-10-11
**Deliverables:**
- Teardown report: `C:\Users\simon\Downloads\REA_whispr_flow_eric_tech\wispr-flow-teardown.html`
- Rebuild: `C:\Users\simon\Downloads\REA_whispr_flow_eric_tech\flowlite\flowlite.py` (64 lines)
- Test receipts: `C:\Users\simon\Downloads\REA_whispr_flow_eric_tech\flowlite\receipts\` (`target.png`, `flowlite_injected.log`, `driver.py`, `target.py`, `flowlite_injected.py`) and the test file `flowlite\test.wav`
- Extraction scripts: `C:\Users\simon\Downloads\REA_whispr_flow_eric_tech\tools\asar.js`, `tools\ctx.js`

**Brief (verbatim, pasted text):**
> 1 Find Wispr Flow in my Desktop folder. Use REA to inspect the app. Use its official website as background.
> 2 Trace how it captures speech, gets transcription results, and inserts text into other apps.
> 3 Explain what you can prove from the app files, what you infer, and what remains hidden.
> 4 Then propose a small working version I could build, including any services it would need.

**Follow-up prompts (verbatim):** "Did you finish the whispr rebuild" → "Rebuild it" → "Test it yourself providing receipts" → "write a development journey explaining how you rebuild Whisperflow using RIA. How does RIA reverse engineer Whisperflow? Give all the details."

I read "RIA" as REA (the `rea-agents` reverse-engineering tool and MCP server) and "Whisperflow" as Wispr Flow. The dictated words have no other match in this session.

---

## 0. The short, honest answer to "How does REA reverse engineer Wispr Flow?"

REA did less of this work than the brief implies. The record is:

- I called REA through MCP two times. **Both calls failed.** Claude Code stopped them because the MCP server sent no progress for 3,385 s and 3,666 s.
- I then ran REA as a command-line tool on part of the app. **That run worked.** It built a static graph of the Electron main process: 11 `BrowserWindow` constructions, 166 IPC handlers, 3 utility processes, and 91,213 semantic relations. Its coverage was "partial".
- The REA graph keeps **no string values**. So it could not show the server hostnames, the gRPC service, the IPC channel names, or the helper's file name. Those facts, which the rebuild depends on, came from my own scripts. The scripts extracted the ASAR and searched the minified bundle text.

So the rebuild's facts come from three sources: (1) REA's structural map of the main process, (2) my direct reading of the bundles, and (3) string scans of the native helper. Section 4 explains what REA does by design, then shows exactly which facts each source gave.

---

## 1. The brief — what was actually being asked

The brief has four parts: locate, trace, classify the evidence, and propose. Two parts carried hidden risk:

- "Find Wispr Flow in my Desktop folder." The app was not there. I had to find it, and the report had to say plainly that it was not on the Desktop.
- "Propose a small working version." This asked for a proposal, not a build. In the first phase I wrote a code sketch into the report and did not build it. When Simon asked "Did you finish the whispr rebuild", the correct answer was "No". He then asked me to build it and to test it with receipts.

## 2. Starting context and invisible constraints

**Environment at minute zero.** Windows 11 Home 10.0.26300; PowerShell 5.1 and Git Bash; working directory `C:\Users\simon\Downloads\REA` (not a git repo); model Claude Opus 5.5 (`claude-opus-5-5`). The REA MCP tools (`mcp__rea__*`) were deferred, so I loaded them with `ToolSearch` before the first call. Some MCP servers had failed to connect at session start (`kb`, `anthropic-financial-services`, `mtnewswire`, `paper`). None of them was needed.

**Rules that shaped the output.** A reader cannot see these, so I list them:
- `~/.claude/CLAUDE.md`: write in ASD-STE100 Simplified Technical English; plain language with no technical content removed; precise phrasing, no rhetoric; HTML output in dark mode (`bg #0f172a`, card `#1e293b`, accents `#fb923c` / `#2dd4bf`); "Never kill a process by name"; "Finish, or say what you left"; "Find the path before you read it".
- `AGENTS.md`: customer-facing docs in HTML, internal docs in Markdown. This journey is an internal doc, so it is Markdown.
- The **Ponytail** hook was active at level "full": do the smallest thing that works. It made the rebuild one file with no new abstractions.
- **Focus mode** was on, so Simon sees only my final message each turn. Every report therefore had to stand alone.
- A **coach-nudge** hook fired at about 204k, 233k and 274k context tokens. It asked me to repeat its text and to suggest `handoff-after-clear` then `/clear`.
- Skills invoked: `reverse-engineer-anything` (the REA skill) at the start, and `dev-journey` for this document.

**What I reused instead of working out again.** The memory index `MEMORY.md` already held "REA JS graph limits — no string values in graph; export bundle when over MCP budget". That note predicted exactly the gap that made REA's graph unable to show hostnames. A second note, "AV blocks Bash curl", is why I never used curl. I also found the folder `C:\Users\simon\Downloads\REA_whispr_flow_eric_tech\`, which held only `README.txt` with this prompt and the YouTube link `https://www.youtube.com/watch?v=FnB9tHKBJXQ`. I made that folder the output location. I did not watch the video.

## 3. Finding the app

1. `Get-ChildItem` on `$env:USERPROFILE\Desktop` and the OneDrive Desktop, filtered on `wispr|flow`, returned exit code 1 with no output.
2. `[Environment]::GetFolderPath('Desktop')` returned `C:\Users\simon\OneDrive\Email attachments\Desktop`, an unusual redirected path. That folder held only `desktop.ini`. `C:\Users\simon\Desktop` held unrelated files (`sticky.html`, `disk_hog_summary.md`, and others).
3. A search of `$env:LOCALAPPDATA`, `$env:APPDATA` and the Program Files folders found `C:\Users\simon\AppData\Local\WisprFlow` and `C:\Users\simon\AppData\Roaming\Wispr Flow`.
4. The install is managed by the Squirrel updater (`Update.exe`, `Squirrel-*.log`). It has three versions: `app-1.4.303`, `app-1.4.338`, `app-1.6.1102`. I chose **1.6.1102**, the newest.

Inventory of `app-1.6.1102`:

| File | What it is | Size |
|---|---|---|
| `Wispr Flow.exe` | Electron shell | 235,430,936 B |
| `resources\app.asar` | All JavaScript, bundled by webpack | 133,651,466 B |
| `resources\Release\Wispr Flow Helper.exe` | Native Windows helper | 20,228,632 B |
| `resources\migrations\*.js` | About 190 Sequelize migrations for `flow.sqlite` | small |
| `resources\ax-inspect.mjs`, `ax-inspect-server.mjs`, `ax-inspect-lib.mjs` | Developer tools that show saved accessibility context of past dictations | 3,806 / 5,314 / 94,717 B |
| `app.asar.unpacked\.webpack\main\native_modules\...` | `node_sqlite3.node`, `crypt32-x64.node`, and a .NET `jabra-device-connector` for headset buttons | — |

## 4. How REA works, and what it actually did on Wispr Flow

### 4.1 What REA is designed to do

REA is a reverse-engineering toolkit. Agents use it through an MCP server (`mcp__rea__*`) or a CLI (`npx -y rea-agents@6.3.0 ...`). The `reverse-engineer-anything` skill says to choose the first tool from the target type:

| Target | First REA tool |
|---|---|
| ASAR or extracted Electron/JavaScript tree | `analyze_javascript_application` |
| Managed .NET PE/CLI assembly | `inspect_managed_artifact` |
| .NET NativeAOT or other native executable | `open_binary` with a native provider (Ghidra, Hopper, or IDA), then `analyze_function`, `procedure_pseudo_code`, `search_strings` |
| A running Electron app | `list_electron_targets`, `capture_electron_scenario` |
| Big results | `inspect_analysis_view` for pages, `export_evidence_bundle` for the full record |

For a JavaScript app, `analyze_javascript_application` does these things:
1. It opens the ASAR, reads its JSON header, and lists every file. It records each file's SHA-256 and checks integrity. With `integrity_policy: "record-and-continue"`, a mismatch is recorded and marked untrusted instead of stopping the run.
2. It parses each JavaScript file into an abstract syntax tree (AST) as inert text. **It never runs the code.** It recovers webpack module factories from AST literals.
3. It builds a **JavaScript Application Graph**: nodes for assets, modules and functions, and edges between them. It summarizes the Electron boundaries: `BrowserWindow` constructions, `webPreferences`, preload scripts, `contextBridge` APIs, IPC handlers and senders, utility processes, and native addon bindings.
4. It builds a **semantic relation graph** with relation families: boundary, call-flow, child-process, closure, configuration, data-flow, event, object-flow, promise-ownership, request, resource-lifecycle, timer.
5. It wraps everything in an **Evidence record**: an `evidence_id`, the subject's SHA-256, the provider, coverage status, `limitations`, and `unknowns`. A missing relation is reported as unknown, not as absent.

For a native binary, REA starts a disassembler provider and gives function lists, pseudocode, cross-references and string searches. For a running app, it can attach to the app and observe it passively. I did not use the runtime path.

### 4.2 What happened when REA was pointed at Wispr Flow

| # | Call | Target | Result |
|---|---|---|---|
| 1 | MCP `analyze_javascript_application` (`integrity_policy: "record-and-continue"`) | `resources\app.asar`, 133,651,466 B | Moved to the background after 120 s (task `kkwqpotnj`). Later: **"Task failed: MCP server "rea" tool "analyze_javascript_application" sent no response or progress for 3385s; aborting."** |
| 2 | MCP `inspect_managed_artifact` | `Release\Wispr Flow Helper.exe` | Background task `k2djhofii`. Later: **"... sent no response or progress for 3666s; aborting."** |
| 3 | CLI `npx -y rea-agents@6.3.0 analyze-javascript-application <dir> --json` | A folder with only `package.json` and the 22 files in `.webpack/main/*.js` | **Success.** Exit 0, 09:47 → 09:54 (about 7 minutes), output 505,348,651 B |

Calls 1 and 2 were stopped by the harness: Claude Code's MCP idle timeout ended them. They were not model errors. Call 2 was also the wrong tool, as section 6 shows. The helper has no CLR header, so it is not a managed assembly.

For call 3, I reduced the target to the 22 main-process bundles so the run could finish. I ran it as a background shell job with a 1,500 s `timeout`, with stdout going to `main_graph.json` and progress going to `main_graph.err`. The progress lines showed the phases: `parse_javascript_source` file by file (1/22 … 22/22), then "Constructing application and Electron boundary relationships", "Sealing the validated application graph", "Binding and validating static semantic relationships", "Hashing the complete application analysis Evidence", and finally `"terminal":true`.

**What REA's CLI returned:**
- Evidence ID: `ev_caa9799415d6a1d4bb802cb454813ff0c86184024019966bd09b79f7a4fe718b`
- Coverage: `partial` (not truncated)
- Statistics: 22 relevant files, 21 JavaScript files parsed, 0 parse failures, 14,127,816 text bytes read, 3,497,416 AST nodes visited, 819 findings
- Electron summary: 11 `browser_windows`, 2 `explicit_web_preferences`, 0 `preload_entrypoints`, 0 `context_bridge_apis`, 3 `utility_processes` (0 entrypoints resolved), 0 `native_addon_bindings`, 1 `sender_validation_observations`
- IPC: 166 operations, all of them `main_handlers`; 155 with literal channels, 11 with dynamic channel expressions; 0 renderer transmissions, because I gave REA no renderer code
- Semantic graph: 91,213 relations kept, 178,512 unknowns. By family: call-flow 4,651; data-flow 36,410; closure 44,551; object-flow 4,979; promise-ownership 373; event 111; boundary 108; timer 25; configuration 5; child-process 0; request 0; resource-lifecycle 0
- Limitations, quoted from REA: "Graph coverage is incomplete; unavailable facts remain explicit and must not be read as absence." / "JavaScript and HTML were parsed as inert text; bundle bootstrap code was never executed." / "Dynamic IPC channel expressions remain unresolved and are never paired by textual similarity."

**The near-miss inside the result.** REA found 0 child-process relations and 0 request relations. A careless reader would conclude "Wispr does not start a helper process and makes no network requests". That is false: section 5 shows `spawn(...)` of the helper and a gRPC client. REA's own limitation note is the guard here. A zero in a partial graph means "not resolved", not "not present".

**The string gap.** I searched the 505 MB Evidence file for `dictation:audioChunk`, `dictation:recordingDone`, `Wispr Flow Helper.exe` and `inference.wisprflow.com`. Each had 0 matches. This confirms the existing memory note: the REA graph keeps no string values.

### 4.3 Which facts came from where

| Fact used by the rebuild | Source |
|---|---|
| Main process has 11 windows, 166 IPC handlers, 3 utility processes | REA CLI |
| Mic capture at 16 kHz, 640-sample AudioWorklet chunks | My extraction plus `ctx.js` on `renderer/hub/index.js` |
| Opus 16 kHz mono 64 kbps, 20 ms packets, IPC `dictation:audioChunk` | `ctx.js` |
| gRPC `flow_api.v1.TranscriptionService/TranscribeStream` and its message schemas | A Node dump of `super("flow_api.v1.*")` in `main/index.js` |
| Server allowlist and `dictation_url.txt` | `main/index.js@3589039` |
| Helper launch through `spawn` with stdio pipes and fd 3 | `main/index.js@4435889` |
| `PasteText{text, htmlText?, pasteId, captureKeystrokeTrace?}` | quicktype schema strings in `main/index.js` |
| Helper uses `SendInput`, `SetClipboardData`, `HTML Format`, `SetWindowsHookExW`, UI Automation | A PowerShell ASCII/UTF-16 string scan of the helper |
| No local ASR model | 0 matches in the ASAR file list for `onnx|ggml|gguf|tflite|.pt|.bin|whisper` |

Rule learned: **REA gives the shape of the app; the strings give its meaning. For a minified Electron app you need both.**

## 5. The core problem: tracing three hops through 9.7 MB of minified code

The main bundle `.webpack/main/index.js` is 9,771,276 B and is mostly a few very long lines. Ordinary line tools fail on it.

### 5.1 Getting at the code
- **ASAR extraction.** I wrote `tools/asar.js` (10 lines, Node standard library only). It reads the 16-byte prefix, the header length at offset 12, and the JSON header at offset 16. It walks `files`, prints every entry (902 in total), and copies out entries that match a regex. File data starts at `8 + headerSize + offset`. The listing showed **no `node_modules` folder**, so everything is bundled. The renderer windows are `hub`, `status`, `overlay`, `scratchpad`, `meeting_recorder`, `feature_tour`, `accessibility_drop`, `meeting_ax_inspector` and `contextMenu`.
- **Search.** My first loop, `grep -oiE` over the bundles, ran past the 120 s limit and went to the background (task `bpp4fxkoo`). The Grep tool gave only per-line counts, so every file reported "1". I then wrote `tools/ctx.js` (5 lines). It runs a regex over the whole file and prints each hit with its **character offset** and N characters of context. Every offset in the report (for example `hub@744855`) comes from this script.

### 5.2 Hop 1 — microphone to main process
1. `getUserMedia|AudioWorklet` matched mostly enum strings, such as `GetUserMediaError="media:getUserMediaError"`. `hub` had 83 matches, which pointed to the `hub` window.
2. In `hub@665196` I found the constants `tf=40, nf=16e3, af={codec:"opus",sampleRate:nf,numberOfChannels:1,bitrate:64e3}` and `lf="../dist/recorderWorklet.js"`.
3. I extracted `renderer/dist/recorderWorklet.js` (1,650 B). `RecorderProcessor` has `chunkSize=640`, handles the messages `"start"` and `"stop"`, and posts Float32 buffers.
4. **Near-miss 1.** The first worklet `onmessage` I found, at `hub@3223941`, converts audio to base64 PCM and sends `ExtensionAudioChunk`. That is the **extension** audio path, not dictation. The dictation handler is `mf.recorderNode.port.onmessage` (`hub@743112`), which calls `handleRecorderWorkletMessage` (`hub@747338`).
5. **Near-miss 2.** The advisor pointed out that the `VB-Audio Virtual Cable` echo-cancellation retry at `hub@685034` is in the **meeting-recorder** setup, not in dictation. I removed it from the dictation steps of the report.
6. **Near-miss 3.** I almost credited `bitrate:64e3` to dictation from its position next to meeting code. I checked it: `hub@758524` builds the dictation encoder with `new AudioEncoder({...})` and configures it with `af`. Each output packet goes to `(0,Oe.$)(S.kH.AudioChunk,…{duration:20, encoding:"opus"…})`. The enum maps `AudioChunk="dictation:audioChunk"` and `RecordingDone="dictation:recordingDone"` (`main@2692782`). **Hop 1 is proven from end to end.**

### 5.3 Hop 2 — main process to the transcription server
1. Endpoint constants at `main@2632015`: `https://api.wisprflow.ai`, `https://api-east.wisprflow.ai`, `wss://api.wisprflow.ai/`, `wss://api-east.wisprflow.ai/`, `ws://127.0.0.1:8300/`, a Supabase URL with an anonymous JWT, a PostHog key, a Sentry DSN, and two Baseten values: a model id `v31pl413` and an API key literal. **I do not copy the key values in any document.**
2. `main@3589039` holds an allowlist: `inference.wisprflow.com` (the default), `model-v31pl413.grpc.api.baseten.co`, and `wispr-ai-prod--prod-grpc-server-flowgrpcserver.us-east.modal.direct`. The app fetches `https://inference-info.wisprflow.com/dictation_url.txt` with an 8 s timeout. It switches only to a host in that set; otherwise it logs "Dictation URL provider returned a target outside the allowlist, ignoring".
3. I looked for gRPC services with `ServiceType\(`, which found nothing. Then `serverStreaming:` found `("flow_api.v1.TranscriptionService",[{name:"Transcribe"…},{name:"TranscribeStream",serverStreaming:!0,clientStreaming:!0…}])` at `main@3692633`. The client is protobuf-ts over `@grpc/grpc-js`.
4. Schema dump: a Node one-liner matched `super("(flow_api\.v1\.[A-Za-z.]+)",[` and printed each field list. It gave about 30 messages: `Request{init, context, payload, commit}`, `Init{metadata, preferences, state}`, `Context{app, textbox, vocabulary, user_identifier, content_text, content_html, session_dictation_apps, screenshot, conversation}`, `AudioPackets{items: bytes, 1..18000}`, `State{progress, raw_text, formatted_text, confidence, candidate_beams, audio_snr, audio_volume, …}`, `Result{output, audio_duration, response_time, transcript_origin ∈ {"", internal, external, internal_experimental, canto_1.0, canto_1.0.1, canto_1.1}, format_skip_reason, …}`, `Response{result, state, all_states, heartbeat}`.
5. Enums. My first attempt used a regex that assumed `AUDIO_ENCODING_` prefixes. It produced 55.3 KB of unrelated enums (ASN.1 tags, HTTP methods, gRPC status codes). The fix was to slice the 40,000 characters after `flow_api.v1.Version` and list every `e[e.X=n]`. That gave: platforms `MACOS WIN32 IOS ANDROID WEB API`; app types `BROWSER PERSONAL_MESSAGING WORK_MESSAGING EMAIL CHATBOT DEVELOPER`; encodings `WAV=1 OPUS=2`; styles `FORMAL CASUAL VERY_CASUAL EXCITED GENZ`; editing strengths `VERBATIM LIGHT MEDIUM HEAVY`; origins `MIXTURE WHISPER SCRIBE VOXTRAL QWEN`; commit `TRUE FALSE`; result status `FORMATTED ERROR RAW_TRANSCRIPT`.
6. Client behavior. I wrote characters 3,694,000–3,740,000 of the bundle to `grpc_client.txt`, with each `;` replaced by a newline, and searched that file:
   - The `getRpcOptions` headers are `authorization: Bearer <user token>`, `baseten-authorization: Api-Key <embedded>`, `baseten-model-id`, `x-baseten-environment`, `flow-debug` and `disable-formatting`.
   - `getContext()` sends the textbox before/selected/after text, accessibility words, OCR words, VS Code variable and file names, nearby text, AX HTML, and **`screenshot:new Uint8Array`, which is empty**.
   - If the heartbeat times out, the app starts a parallel **unary gRPC `Transcribe`** call (the code calls it the "Baseten HTTP fallback"). The first answer wins (`raceWinner`).

### 5.4 Hop 3 — main process to the target app
1. `main@4435889` chooses `${resources}\Release\Wispr Flow Helper.exe` and starts it with `spawn(s,{stdio:["pipe","pipe","pipe","pipe"]})`. Requests go to the helper on stdin. Replies come back on **fd 3**: `ee.on("data", e=>pushData(...))`.
2. I counted `sendHelperRequest)("X"` calls: `CancelPaste DictationStart DictationStop SimulateKeyPress(13) UpdateShortcuts(6) StartAccessibilityServices SetFocusMode …`. There was no PasteText among them. PasteText is sent through a different wrapper, `y("PasteText",…)`, at `main@4465164`. Just before that call, main runs `r.clipboard.readText()` and logs "Saved clipboard contents before paste".
3. The payload schemas are quicktype-generated objects such as `PasteTextPayload:L([…captureKeystrokeTrace?, htmlText?, pasteId, text])`, `PasteOutcomePayload{pasteId, success, timeElapsedMs}` and `TextBoxInfoPayload{accessibilityIsFunctioning, afterText, beforeText, contents, couldNotGetTextBoxInfo, focusedElementHash, isEditable, selectedText}`. Getting there took four broken attempts: a bash-escaped `RegExp` failed with "SyntaxError: Invalid regular expression: … Unterminated group", then "Unterminated character class", and a slice bug printed only "P". The final version simply printed the 900 characters after a literal `indexOf`.
4. A PowerShell scan of the helper (ASCII plus two UTF-16 alignments) found `PasteViaClipboard`, `ClipboardSnapshot`, `ClipboardRestore`, `ClipboardRestorePolicy`, `SetClipboardData`, `HTML Format`, `SendInput`, `ShiftInsert`, `SetWindowsHookExW`, `LowLevelKeyboardProc`, `IUIAutomationTextPattern`, `IUIAutomationValuePattern`, `IUIAutomationLegacyIAccessiblePattern`, and `PasteTextHandler`.

## 6. Classifying the helper (a failed side-quest)

- The first marker probe found `BSJB: True`, `System.Private.CoreLib: True`, `mscoree.dll: False`, `rustc: True`, `SendInput: True`.
- I found the .NET single-file bundle signature (`8b1202b96a612038…`) at offset 11,270,120. I wrote `bundle.js` to parse the manifest. It crashed: "RangeError [ERR_OUT_OF_RANGE]: The value of "offset" is out of range. … Received 576_460_745_995_190_300". The 8 bytes before the signature were `feffff87feffff07`, which is code, not a header offset.
- The PE section table shows `.text .rdata .data .pdata .rsrc .reloc` and a CLR header directory of `0 0`. **There is no managed header, so this is NativeAOT.** The signature is an embedded constant, not a bundle. I dropped `bundle.js`.
- Rule learned: **check the CLR header directory first; "System.Private.CoreLib" in the strings does not mean a managed PE.**
- I did not decompile the helper. It would need `open_binary` with Ghidra on 20 MB of machine code, and the REA MCP calls had already timed out on smaller work.

## 7. Design decisions

| Decision | Chosen | Rejected, and why |
|---|---|---|
| Version to analyze | 1.6.1102 | The 1.4.x versions are older and are kept only for Squirrel rollback |
| REA target after the timeouts | CLI on the 22 main bundles | The full ASAR over MCP died twice; a renderer pass was skipped to finish in the session |
| How to read minified code | My own `asar.js` + `ctx.js` | `npx @electron/asar` would add a download; grep is too slow on very long lines |
| Report format | Dark-mode HTML | Required by the CLAUDE.md HTML rule; Markdown is used only for this internal doc |
| Secrets | Name them, never copy them | Copying would spread live credentials |
| Rebuild ASR | Local `faster-whisper` `base.en` on CUDA | A cloud API needs a key and costs money; Simon already runs faster-whisper; Wispr's own service is closed |
| Hotkey library | `keyboard` | `pynput` would be equal in size; `keyboard.is_pressed` makes hold-to-talk one line |
| Text insertion | Clipboard + Ctrl+V + restore, the same mechanism as Wispr | `SendInput` per character is slow and breaks on Unicode; UI Automation ValuePattern does not work in every app |
| Scope cuts (Ponytail) | No streaming, no context, no LLM cleanup, no paste check, no settings file | Each cut is listed as a limit in the report |
| Self-check | One `--test <wav>` flag | The Ponytail rule asks for exactly one runnable check |
| End-to-end test | Hold F9 with a synthetic key press, paste into a separate test app | Pasting into Notepad risks Simon's open session tabs; my own test window can save its text to a file |

## 8. The rebuild and its tests

### 8.1 Building `flowlite.py`
- Probe: Python 3.13.5. `faster_whisper`, `sounddevice`, `numpy`, `pyperclip` and `ctranslate2` were already installed; `keyboard` was missing. `ctranslate2.get_cuda_device_count()` returned 1, and `nvidia-smi` showed "NVIDIA GeForce RTX 3050 Laptop GPU, 4096 MiB".
- `python -m pip install keyboard`. This was the only package installed.
- The file has 64 lines: `load_model()` (CUDA float16, falling back to CPU int8), `transcribe()` (`vad_filter=True`), `record()` (16 kHz mono float32 `InputStream` while F9 is held), `paste()` (save clipboard → copy → `ctrl+v` → 0.15 s → restore), and `main()` with `--test`. Two `ponytail:` comments mark the known limits: the fixed delay and the text-only restore.

### 8.2 Self-test on a synthetic voice
- Test audio: `System.Speech` SpeechSynthesizer at 16,000 Hz, 16-bit, mono → `test.wav`, 144,526 B, about 4.5 s, text "Let's meet at six PM on Thursday to review the quarterly report."
- **Failure:** PowerShell variable names ignore case, so `$S` (the folder) and `$s` (the synthesizer) were one variable. Error: "Could not find a part of the path 'C:\Users\simon\Downloads\REA\System.Speech.Synthesis.SpeechSynthesizer\test.wav'". The fix was to rename the variables to `$dir` and `$syn`.
- `python flowlite.py --test test.wav` → `Let's meet at 6 p.m. on Thursday to review the quarterly report.` Total time 20.2 s (first run), then 19.7 s.
- **Failure:** my timing script used `python -I` and got "ModuleNotFoundError: No module named 'faster_whisper'". The `-I` flag hides user site-packages. I ran it again without `-I`; it is safe here because the code is my own. Measured result: device `cuda`, 16.4 s to import and load the model, ASR 0.63 s on the first call and 0.23 s on the second, for 4.5 s of audio.
- Separate checks: default input "Microphone Array (2- Intel® Sma"; a 0.5 s mic sample gave RMS 1.46e-05; `keyboard.is_pressed('f9')` returned False with no error; clipboard set and restore both gave True.
- I started the live app as background task `baxca8zzt`. Its output: "Ready. Hold F9 and speak. Ctrl+C to quit."

### 8.3 "Test it yourself providing receipts"
**Test setup:** `target.py` is a topmost tkinter window titled `flowlite-e2e-target`. It saves its text to `target_text.txt` every 0.3 s. `driver.py` does the rest:
1. Puts the marker `CLIPBOARD-SENTINEL-<unix time>` on the clipboard.
2. Starts the target and stores its PID.
3. Waits until `GetForegroundWindow` belongs to the target, using an Alt press and `SetForegroundWindow`. If the target never becomes the foreground window, it **stops without pressing F9**. This guard keeps a paste from landing in Simon's own window.
4. Holds F9 through `keyboard.press`, plays the WAV, releases F9, and waits 6 s.
5. Takes a screenshot of the target with `ImageGrab`, then reads the target's text and the clipboard.

| Run | Audio path | flowlite log | `target_text` | Clipboard restored |
|---|---|---|---|---|
| 1 | Default output = "Headset Earphone (Plantronics B" → laptop mic | `4.9s audio, 0.13s ASR: ''` | `""` | true |
| 2 | Forced output "Speaker (3- Realtek(R) Audio)" (MME) → laptop mic | `5.5s audio, 0.01s ASR: ''` | `""` | true |
| 3 | WAV fed in place of the mic by `flowlite_injected.py` | `5.1s audio, 0.85s ASR: "Let's meet at 6 p.m. on Thursday to review the quarterly report."` | `"Let's meet at 6 p.m. on Thursday to review the quarterly report. "` | true |

**Diagnosis of runs 1–2.** The first run played the speech into the headset, where the laptop mic could not hear it. For the second run I used `sd.playrec` on the Realtek speaker and the Intel mic. The mic got RMS 1.72e-04 and peak 7.08e-03, about 12 times the 1.46e-05 silence level, but still too quiet to transcribe. Whisper returned `''` with VAD and `''` without VAD. After I scaled the audio to full level, it returned "Let's be that welcome.", which is wrong text. So raising the gain in software does not fix this; the problem is in the sound path. I did not read or change the Windows volume settings.

**Run 3 design.** `flowlite_injected.py` imports the unchanged `flowlite` module and makes one swap: `flowlite.sd.InputStream = FakeStream`. FakeStream feeds the WAV in 640-sample blocks every 40 ms, which is real time, then silence. Before run 3 I stopped the live task with `TaskStop baxca8zzt`, so two copies would not both paste. The driver starts the injected flowlite as a subprocess, waits for "Ready.", and at the end kills it **by its own captured PID** (44868). The CLAUDE.md rule forbids killing by name.

**Receipts saved:** `flowlite/receipts/target.png` (the screenshot shows the sentence in the `flowlite-e2e-target` window), `flowlite_injected.log`, and the three test scripts. A check after the test showed PIDs 44868, 1792, 25916 and 56228 all "gone".

## 9. Tools used in this session

| Tool | What it did here |
|---|---|
| `Skill` | Loaded `reverse-engineer-anything` and `dev-journey` |
| `ToolSearch` | Loaded the REA MCP schemas, `WebFetch` and `TaskStop` |
| `mcp__rea__analyze_javascript_application` | Full ASAR; died on the idle timeout after 3,385 s |
| `mcp__rea__inspect_managed_artifact` | Helper; died on the idle timeout after 3,666 s; the target is NativeAOT, so the tool did not apply |
| REA CLI `rea-agents@6.3.0` | Main-process graph, Evidence `ev_caa97994…`, 505 MB JSON |
| `WebFetch` | `https://wisprflow.ai` (claims: "4x faster than your keyboard", works "anywhere you can type") and `https://wisprflow.ai/privacy` ("Transcription always happens in the cloud", "Reads limited text from the app you're dictating into") |
| Bash + Node | `asar.js`, `ctx.js`, schema and enum dumps, `bundle.js` (failed) |
| PowerShell | Install discovery, helper string scan, PE section table, TTS WAV, timing, cleanup checks |
| `Read` | `ax-inspect.mjs`, `ax-inspect-server.mjs`, the screenshot receipt |
| `Write` / `Edit` | Report HTML, `flowlite.py`, memory file, this journey |
| `advisor` | Two consultations (section 10) |
| `TaskStop` | Stopped the live flowlite task `baxca8zzt` by task ID |

## 10. Agents and AI machinery

The whole session ran on Claude Opus 5.5 with no subagents; all work was inline. The advisor was called two times in the first phase:
1. **Before writing.** It told me to: put the coach note first; redact the four secrets; say plainly that the app was not on the Desktop; call the REA failures a harness failure and cite the CLI Evidence; stop chasing the helper bundle; prove the renderer-to-main IPC hop; prove the absence of a local model with a bounded search. It also listed labelling traps: 64 kbps, "SCRIBE" meaning ElevenLabs is only a guess from the name, the paste order is inferred, the "HTTP fallback" is really unary gRPC, the empty screenshot, and the default hotkey is unknown. **This changed the report.** I added the IPC proof (`dictation:audioChunk`), the bounded model search, and the corrected labels.
2. **Before finishing.** It caught the VB-Audio sentence, which is meeting code, and two unmeasured claims: "usually under 1 s", and "before and during dictation". **I fixed all three.**

## 11. Human-in-the-loop moments

Simon wrote five prompts: the brief, "Did you finish the whispr rebuild", "Rebuild it", "Test it yourself providing receipts", and this request. He approved nothing interactively; permissions were in bypass mode. He did not do the live voice test, which is the one test that needs a person.

## 12. Costs and limits

- No paid API calls. ASR ran locally; the WebFetch calls were free.
- Time: the two MCP timeouts used about 56–61 minutes of wall-clock in the background. The REA CLI took about 7 minutes. Model load takes 16.4 s on each start.
- Context: the coach hook reported about 204k, 233k and 274k tokens as the session grew. Its note says sessions like this one were about 49% of historical spend.
- Disk: about 505 MB of REA JSON plus the extracted ASAR, both in the session scratchpad, which is deleted with the session.

## 13. Verification summary

| Claim | How it was checked |
|---|---|
| The app is not on the Desktop | Listings of three Desktop paths |
| Every pipeline fact in the report | A file and character offset, recorded in the report's evidence table |
| No local ASR model | 0 matches in 902 ASAR entries; the only "model" hit is the Jabra `GNAudio.DeviceApis.ModelBase.dll` |
| REA graph numbers | Read from `main_graph.json` with Node |
| Rebuild transcribes correctly | `--test` output matches the TTS script |
| Rebuild runs on the GPU | `m.model.device == cuda`, timings measured |
| Full pipeline pastes into another app and restores the clipboard | Run 3: target text file, screenshot, and clipboard marker before and after |
| No processes left running | `Get-Process -Id` on each PID → "gone" |

**Not verified:**
- A real voice into the real microphone (runs 1–2 failed; see section 8.3).
- The helper's paste key combination and timing (not decompiled).
- Anything at runtime in Wispr Flow itself (the app was never run).
- The `wss://` constants in the dictation path.
- The Windows OCR engine.
- The default hotkey.

## 14. Unfinished business

1. **Live voice test.** Not done, because it needs a person to speak, and the speaker-to-mic path is too quiet (RMS 1.72e-04). To finish it, Simon runs `python flowlite.py`, holds F9, and speaks. If the log shows `''`, raise the mic level or use the Plantronics headset mic (flowlite would then need a `device=` argument). The rebuild works without this test; run 3 proves every stage except the acoustic one.
2. **Helper decompile.** Not done (20 MB NativeAOT; needs a Ghidra provider; MCP timeouts). It would show which key combination is used per app and when the clipboard restore is skipped.
3. **REA on the renderer bundles.** Not done. It would pair renderer senders with the 166 main handlers.
4. **YouTube video in `README.txt`.** Not watched.
5. **Re-running the receipts.** `driver.py` expects `flowlite\test.wav` (now in place) and these arguments: `python flowlite\receipts\driver.py <receipts dir> inject <flowlite dir>`. `driver.py` writes `target_text.txt`, `target.png` and `flowlite_injected.log` into the receipts folder, so a re-run overwrites the saved receipts. It also needs `target.py` and `flowlite_injected.py` in the same folder, which they are.

## 15. Knowledge captured

- Memory: `C:\Users\simon\.claude\projects\C--Users-simon-Downloads-REA\memory\rea-mcp-timeout-large-asar.md`, with an index line in `MEMORY.md`. It records that REA MCP times out on a 133 MB ASAR, that the fix is to run the CLI on an extracted subset, and that a NativeAOT helper is not a managed PE.
- Report: `wispr-flow-teardown.html`, with proven, inferred and hidden labels, a server table, and an evidence-offset table.
- Scripts moved out of the scratchpad: `tools/asar.js`, `tools/ctx.js`, `flowlite/receipts/*`, `flowlite/test.wav`.

Rules learned in this session:
- "A zero in a partial REA graph means unresolved, not absent."
- "REA gives the shape; the strings give the meaning."
- "Check the CLR header before calling a .NET binary managed."
- "PowerShell variable names ignore case: `$S` is `$s`."
- "`python -I` hides user site-packages."
- "Prove the acoustic path separately from the software path."

## 16. Where things stand

- The teardown is complete for static analysis of 1.6.1102. Its proven, inferred and hidden labels are in the report.
- `flowlite.py` works from end to end on injected audio, with receipts. It has not been tested with a live voice.
- Nothing is running.
- Published (at Simon's request) to the public repo `https://github.com/az9713/wispr-flow-rea-teardown`. Before the commit, I cropped `flowlite/receipts/target.png` to the test window only, because the first capture showed fragments of other windows. No secret values are in the repo; a search for the five embedded secret patterns found 0 files.

Next steps (options):
1. **Live voice test.** Run the live test and fix the mic path.
2. **Add context.** Add a dictionary through faster-whisper's `initial_prompt`.
3. **Add cleanup.** Add an optional LLM cleanup step.
4. **Check the paste.** Add a UI Automation read-back, as Wispr's `DictatedTextVerification` does.
5. **Read the helper.** Run a Ghidra pass on `Wispr Flow Helper.exe` to learn its paste rules.
