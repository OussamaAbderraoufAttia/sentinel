$GCC = "gcc"

Write-Host "--- Compiling Manual SENTINEL ---" -ForegroundColor Cyan
& $GCC -Wall `
    manual/main.c `
    manual/analyse_lexicale/lexer.c `
    manual/analyse_lexicale/lexer_nfa.c `
    manual/analyse_syntaxosemantique/parser.c `
    manual/analyse_syntaxosemantique/symbols.c `
    -o sentinel_manual.exe

if ($LASTEXITCODE -eq 0) {
    Write-Host "✅ Build successful: sentinel_manual.exe created in root." -ForegroundColor Green
} else {
    Write-Host "❌ Build failed." -ForegroundColor Red
}
