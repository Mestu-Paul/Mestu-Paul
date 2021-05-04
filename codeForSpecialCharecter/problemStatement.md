Recently I have noticed that my hard drive was getting filled and it is high time I did some cleanup. However, it is quite tedious work to check each and every file to determine whether I need it or not. Luckily, I always maintain my important files according to a predefined structure of important folders. This means, any file that isn't contained in an important folder is not an important file and can be deleted. Note that, there might be unimportant folders inside an important folder.

That just solves part of the problem, I will still have to go inside each folder and see if it has been marked as important or not. To save my time, I would like to automate the process, and this is where your assistance is required.

I have managed to generate a tree structure of important folders and a list of fully qualified paths of all files on my hard drive. Your task is to determine the number of files that can be deleted. I will show you an example here.

The tree structure will be given in the following format:
<p align="right">
  <img width="900" height="200" src="https://user-images.githubusercontent.com/55883634/117006815-b43b5e80-ad0a-11eb-87cc-3d9edc90654a.png">
</p>

As you can see, some special ASCII characters have been used to show you the proper folder hierarchy. Note that, each subfolder is indented exactly 4 characters to the right from the parent folder. There will always be a root folder containing one or more important subfolders. There can be at most 5 level deep subfolders inside the root folder and each subfolder may contain a maximum of 5 folders.

Any file contained in a folder that is not a subfolder in the given structure of important subfolders will not be considered as important. Now, let's examine some file paths and see if they are important or not according to the above structure:

<h5>/root/abc.txt -> Not important, not inside any subfolder<br>
/someplace/music/rain.mp3 -> Not important, not inside root folder<br>
/root/videos/godzilla.mp4 -> Not important, /videos is not present as important<br>
/notes.txt -> Not important, not inside root folder<br>
/root/documents/crash.log -> Important, inside a given subfolder<br>
/root/documents/projects/test/a.cpp -> Not important, /test is not present as important<br>
/root/documents/projects/a.cpp -> Important, inside a given subfolder</h5>

Paths will always start with a ‘/’ character. Every folder name will be composed of alpha-numeric Latin ('a'-'z', 'A'-'Z', '0'-'9') characters only. However, every file name will have exactly 1 dot (‘.’) character separating the name and the extension, both of which will be composed of alpha-numeric Latin characters as well. Each path entry will always have the file name as the last component, separated by ‘/’ characters. Note that subfolders in query can be more than five levels deep.

Your solution will be tested against several test cases. Check input and output sections for further details.

**Input :**<br>
<pre>
2

root
├── documents
│   └── projects
└── downloads
    ├── friends
    └── stargate

7
/root/abc.txt
/someplace/music/rain.mp3
/root/videos/godzilla.mp4
/notes.txt
/root/documents/crash.log
/root/documents/projects/test/a.cpp
/root/documents/projects/a.cpp

root
├── 263736
│   └── 602922
└── 57712
    ├── 528651
    └── 844640

5
/root/4083.txt
/root/263736/2728.txt
/root/263736/5769.txt
/root/263736/602922/7321.txt
/root/263736/602922/198.txt
</pre>
**Output :**
<pre>
Case 1: 5
Case 2: 1
 </pre>
