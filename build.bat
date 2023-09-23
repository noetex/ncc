@echo off

call cl ncc.c /Fe:ncc.exe /nologo /W3 /Zi /link /WX /incremental:no /opt:icf,ref
