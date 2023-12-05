rm -rf build
mkdir build
cd build
cl  /DUNICODE /D_UNICODE  /EHsc ..\src\WaitFor.cpp
javac -d . ..\src\Main.java
jar cfe Hello.jar Main *.class
cd ..
rm -rf package
mkdir package
cd package
jpackage --input ..\build  --name HelloWorld  --main-jar Hello.jar   --main-class Main   --type app-image
cd ..

