1. Build OpenCV
2. Install OpenCV
3. Link OpenCV libs and headers
3.1 Project > Properties
3.2 Platform > x64 (OpenCV default targets x64)
3.3 C/C++ > General > include: C:\Repos\opencv\out\install\x64-Debug (default)\include
3.4 C/C++ > General > using: C:\Repos\opencv\out\install\x64-Debug (default)\include
3.5 Linker > General > Additional Library Directories: C:\Repos\opencv\out\install\x64-Debug (default)\x64\vc16\lib
3.6 Linker > Input > Additional Dependencies: opencv_highgui440d.lib;opencv_core440d.lib;opencv_features2d440d.lib;opencv_flann440d.lib;opencv_imgcodecs440d.lib;opencv_imgproc440d.lib;opencv_ml440d.lib;opencv_objdetect440d.lib;opencv_videoio440d.lib
4. Build project.
5. Copy over OpenCV C:\Repos\opencv\out\install\x64-Debug (default)\x64\vc16\bin dlls to your target directory.