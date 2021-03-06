# Building on Windows

Prerequisites:

- Visual Studio 2015
- [cmake](https://cmake.org/) version 3.9+ on the PATH (I used 3.9.6)
  
Optional, but recommended:

- [Microsoft Child Process Debugging Power Tool](https://marketplace.visualstudio.com/items?itemName=GreggMiskelly.MicrosoftChildProcessDebuggingPowerTool)

Initial build steps:

1. Open command prompt in working copy folder 

2. Run `snmake init` (`snmake.exe` is supplied) - you should get a
   bunch of output. There may be the odd warning but there should be
   no obvious errors and it should finish with an exit code of 0
   
General day-to-day build steps:

1. Load `build\win64\b2.sln` or `build\win32\b2.sln` into Visual
   Studio 2015

2. Build

3. Run

Because of the way cmake works, there are 40+ projects in the
solution. Even though most are never used, they're still there
cluttering the place up. You just have to put up with this.

The 32-bit version is unsupported, though I do build and run it from
time to time, so it ought to work.

# Running the automated tests

Set the startup project to be `visual_studio_test_runner`, build, and
run. This runs the full set of tests, such as it is, and takes about 4
minutes on my laptop.

You can exclude the slow tests with the
`visual_studio_test_runner_subset` project, which finishes in about 5
seconds.

If you have the child process debugging tool installed, the debugger
will attach to each test case as it is executed. This does add
overhead but makes debugging a lot easier.

Each test case has its own project in the solution, so you can also
run them independently. Some do require command line options - consult
the corresponding CMakeLists.txt for details.
