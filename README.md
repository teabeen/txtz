# TextStatz - txtz
### *analyze text files 📊📝*



#### *What is this?? 🤔*
<p>TextStatz is a lightweight text file analyzer. It is useful for getting fiel content stats quickly.</p>

## Installing 🚀
*currently only avaiable on Linux (unless compiled on Windows and MacOS using Premake*)
### Option one - Building from source🛠️  
**More options coming soon**

### *Linux*
```
git clone https://github.com/VilliasDev/txtz.git # Clone the repository
cd txtz
./premake5 gmake # Generate build files using premake5
cd build
make config=release # Build the project

# OPTIONAL (But recommended): Move the binary to a directory included in the 
# system's PATH
cd ..
cd bin
cd Release
sudo mv txtz /usr/local/bin/


```


### Uninstalling from PATH (If installed using the option above)
```
rm /usr/local/bin/txtz
```




### Usage 🖥️

```
~txtz file.txt #works with other file types too

Filename: file.txt
Filetype: txt
Filesize: 49 bytes
Lines: 1
Words: 6
Characters: 22

```
*Analyzes the file and returns the file info *

## Contributors:

### [VilliasDev](https://github.com/VilliasDev) (Owner) 👩‍💻





