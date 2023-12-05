rm -rf build
mkdir build
cd build
cl  /DUNICODE /D_UNICODE  /EHsc ..\src\WaitFor.cpp
"%JAVA_HOME%\bin\javac.exe" -d . ..\src\Main.java
"%JAVA_HOME%\bin\jar.exe" cfe Hello.jar Main *.class
cd ..
rm -rf package
mkdir package
cd package
"%JAVA_HOME%\bin\jpackage.exe" --input ..\build  --name HelloWorld  --main-jar Hello.jar   --main-class Main   --type app-image
cd ..

