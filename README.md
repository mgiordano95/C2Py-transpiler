<!-- Project Logo -->
<br />
<div align="center">
  <a href="https://github.com/mgiordano95/C2Py-transpiler">
    <img src="Assets/logo-dark.png" alt="Logo" width="389" height="52">
  </a>

  <h3 align="center">
    <a href="https://github.com/mgiordano95/C2Py-transpiler">C2Py Transpiler</a>
  </h3>

  <p align="center">
    C to Python Source to Source Transpiler
    <br />
    <br />
    <a href="https://github.com/mgiordano95/C2Py-transpiler/issues">Report Bug</a>
    ·
    <a href="https://github.com/mgiordano95/C2Py-transpiler/issues">Request Feature</a>
  </p>
</div>

<!-- Table Of Contents -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li><a href="#requirements">Requirements</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

<!-- About The Project -->
## About The Project


### Built With

[![c][c]][c-url] 

[![python][python]][python-url]


## Requirements

Windows:
1. [Download](https://sourceforge.net/projects/gnuwin32/files/flex/2.5.4a-1/flex-2.5.4a-1.exe/download) and Install Flex v. 2.5.4
2. [Download](http://downloads.sourceforge.net/gnuwin32/bison-2.4.1-setup.exe) and Install Bison v. 2.4.1
3. [Download](https://sourceforge.net/projects/wxdsgn/files/latest/download) and Install wxDev-C++ (wxdevcpp_7.4.2_full_setup.exe), a fork of Dev-C++ which includes the gcc compiler
4. Include in the PATH environment variable the bin subdirectories
of the compiler, Flex and Bison:
  - C:\GnuWin32\bin
  - C:\Program Files (x86)\Dev-Cpp\MinGW32\bin

Ubuntu/Debian:
1. Open a terminal window using Ctrl + Alt + T.
2. Update the system's package list by typing the following command and pressing Enter:

    `sudo apt-get update`

3. Install Flex typing the following command and pressing Enter:

    `sudo apt-get install flex`

4. Install Bison typing the following command and pressing Enter:

    `sudo apt-get install bison`

5. Verify that the installations were successful by typing the following commands and pressing Enter:

    `flex --version`

    `bison --version`

To compile this project we used:
- Flex v. 2.6.4
- Bison v. 3.8.2
- GCC v. 11.3.0


<!-- Usage -->
## Usage

1. Download ZIP.
2. Open a terminal window using Ctrl + Alt + T.
3. Go to the "transpiler" directory.
4. Run the following commands:

    `bison -d parser.y`

    `flex lexer.l`

    `gcc parser.tab.c lex.yy.c -lfl -lm` 

5. Or, symply run the following command:

    `make`

6. Run the transpiler with the command:

    `./a.out`

7. Or, run the command:

    `./a.out < source_file.c`


<!-- License -->
## License

Distributed under the MIT License. See `LICENSE` for more information.


<!-- Contact -->
## Contact

Mauro Giordano - m.giordano8@studenti.poliba.it

Francesco Palumbo - f.palumbo3@studenti.poliba.it

Project Link: [https://github.com/mgiordano95/C2Py-transpiler](https://github.com/mgiordano95/C2Py-transpiler)


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[c]: https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white
[python]: https://img.shields.io/badge/Python-FFD43B?style=for-the-badge&logo=python&logoColor=blue
[json]: https://img.shields.io/badge/json-5E5C5C?style=for-the-badge&logo=json&logoColor=white

[c-url]: https://www.w3schools.com/c/c_intro.php
[python-url]: python.org
[json-url]: https://www.json.org/