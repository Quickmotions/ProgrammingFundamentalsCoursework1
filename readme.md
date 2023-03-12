<h1>Coursework 1 Application</h1>
Built by Fergus Haak - 13/03/2023

<h3>How to Build</h3>
The Microsoft Compiler is to be used for building this application.

Using the command `nmake` will build the application when used in the source directory.
- This will clean unneeded files during build process as required.


Using the command `nmake clean` will clean all files created by the build process.
- This includes the .exe and the .s output file.

<h3>How to Use</h3>
Use the command `main [input_file]` where [input_file] is the location of the C file you would 
like to diagnose using this application

The Application will return the following data about the [input_file]:
- Character Count
- Line Count
- Comment Count
- Variable Count
- Build an output .s file with all variables and the amount of times they were using during the program.
