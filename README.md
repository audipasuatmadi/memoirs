# Memoirs
## Background
This project is born out of a problem on my personal experience. I got irritated whenever I import references file as Microsoft Word's xml from Mendeley, I have to edit some of the source xml to be compatible with my Microsoft Word.

This program is made to automate just that above. I decided to make it open-source at GitHub in case anyone experience the same issue with Mendeley's Microsoft Word export as I am.

Here's an example of a corrupted Mendeley's `Sources.xml` on Microsoft Word.
<img width="1231" alt="Screen Shot 2023-01-08 at 03 04 48" src="https://user-images.githubusercontent.com/63685606/211167593-48680577-64e9-45eb-9539-7f2a342e2668.png">

Here's an example of a fixed Mendeley's `Sources.xml` after using memoirs.
<img width="1183" alt="Screen Shot 2023-01-08 at 03 20 18" src="https://user-images.githubusercontent.com/63685606/211167598-9f629936-4ba4-469c-b6dc-7089bd1ad4eb.png">



Feel free to contribute in case you found a way to optimize / you got an idea on improving this program.
Thank you very much 😄
Regards, Putu Audi Pasuatmadi

## How to Use
### Building
You can build this program using CMake. Configure your CMake with the kit of your choice, then run build on your CMake tool. Then your program will be at `build` folder if you have the default build output configuration of the CMake.

### Running
`-help`: to show available commands
`-source`: to give the `Sources.xml` that you wish to fix.
`-out`: to give where the file fix file shall be written.
example
```
./memoirs -source ./CorruptedSources.xml  -out ./Sources.xml
```

## Contributing
Feel free to contribute to this mini open-source project! kindly make a pull request and please notify me via email or other media. Thank you!
