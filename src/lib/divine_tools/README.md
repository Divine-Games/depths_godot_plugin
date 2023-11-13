# README

At depths_godot_plugin/depths_game_server

```powershell
$env:GOOS="linux"
$env:GOARCH="amd64" 
go build -o ../src/lib/divine_tools/libmapgen_linux.a -buildmode=c-archive .
$env:GOOS="windows"
$env:GOARCH="amd64"
go build -o ../src/lib/divine_tools/libmapgen_windows.a -buildmode=c-archive .
```

```bash
GOOS="linux" GOARCH="amd64" go build -o ../src/lib/divine_tools/libmapgen_linux.a -buildmode=c-archive .
GOOS="windows" GOARCH="amd64" go build -o ../src/lib/divine_tools/libmapgen_windows.a -buildmode=c-archive .
```