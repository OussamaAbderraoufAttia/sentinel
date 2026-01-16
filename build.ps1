$FLEX = "C:\flex\win_flex.exe"
$BISON = "C:\flex\win_bison.exe"
$GCC = "gcc"

# Set Bison data directory
$env:BISON_PKDATADIR = "C:\data"

Write-Host "--- Generating Parser ---" -ForegroundColor Cyan
Push-Location Analyse_Syntaxosemantique
& $BISON -d sentinel.y
Pop-Location

Write-Host "--- Generating Lexer ---" -ForegroundColor Cyan
Push-Location Analyse_Syntaxosemantique
& $FLEX sentinel.l
Pop-Location

Write-Host "--- Compiling SENTINEL ---" -ForegroundColor Cyan
& $GCC -Wall -ICompiler_Core -IAnalyse_Syntaxosemantique `
    Analyse_Syntaxosemantique/lex.yy.c `
    Analyse_Syntaxosemantique/sentinel.tab.c `
    Compiler_Core/main.c `
    Compiler_Core/symbol_table.c `
    Compiler_Core/quads.c `
    -o sentinel.exe

if ($LASTEXITCODE -eq 0) {
    Write-Host "✅ Build successful: sentinel.exe created in root." -ForegroundColor Green
} else {
    Write-Host "❌ Build failed." -ForegroundColor Red
}
