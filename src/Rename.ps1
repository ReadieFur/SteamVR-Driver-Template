#====START USER CONFIGURATION====
$search = "TemplateProject"
$replace = "MyProject"
#====END USER CONFIGURATION====

Write-Host "Renaming project files and folders from '$search' to '$replace'..."
Get-ChildItem -File | ForEach-Object {
    #Rename instance of $search in the file
    $newName = $_.Name -replace $search, $replace
    $content = Get-Content $_.FullName -Raw
    $content = $content -replace $search, $replace
    Set-Content $_.FullName $content

    #Rename the file
    if ($_.Name -notlike "*$PSCommandPath*" -and $_.Name -like "*$search*") {
        Rename-Item $_.FullName -NewName $newName -Force
    }
}
Write-Host "Done."
