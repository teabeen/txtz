# TextStatz - txtz
### *analyze text files 📊📝*



#### *What is is? 🤔*
<p>TextStatz, or as we affectionately call it - txtz, is your go-to tool when you need a dash of personality while analyzing text files. Developed in the quirky realm of C, txtz is not your typical, run-of-the-mill text file analyzer. This is a hobby project, crafted with love and a sprinkle of humor, rather than aiming to outshine the more serious contenders in the field 😄</p>

## Features:
- **Minimalistic Mojo:** txtz keeps it simple and straightforward, focusing on providing essential file statistics without overwhelming you with unnecessary details. (Because sometimes less is more! 💡)
- **Efficient Analysis:** Written in C for optimal performance, txtz swiftly crunches through your text files, delivering results in a blink. (Because who has time to wait? ⏲)

## Installing 🚀

### Option one - Building from source 🛠️  
**More options coming soon**
```
git clone https://github.com/VilliasDev/txtz.git # Clone the repository
cd txtz
./premake5 gmake # Generate build files using premake5
cd build
make # Build the project

# OPTIONAL (But recommended): Move the binary to a directory included in the 
# system's PATH
cd ..
cd bin
sudo mv txtz /usr/local/bin/


```
> Note: The binary is located in /bin/Debug/

### Usage 🖥️

```
~txtz file.txt #works with other file types too

Filename: file.txt
Filetype: txt
Lines: 1
Words: 6
Characters: 22

```
*Analyzes the file and returns the file info *

## Contributors:

### [VilliasDev](https://github.com/VilliasDev) (Owner) 👩‍💻





