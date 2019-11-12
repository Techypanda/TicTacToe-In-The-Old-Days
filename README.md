<!--
*** Thanks for checking out this README Template. If you have a suggestion that would
*** make this better, please fork the repo and create a pull request or simply open
*** an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
***
***
***
*** To avoid retyping too much info. Do a search and replace for the following:
*** github_username, repo, twitter_handle, email
-->





<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->


<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/Techypanda/UCP-Assignment-2019">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">UCP Assignment 2019</h3>

  <p align="center">
    The TicTacToe assignment written in C89 for my Computer Science Degree (100%)
    <br />
    <a href="https://github.com/Techypanda/UCP-Assignment-2019"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Techypanda/UCP-Assignment-2019">View Demo</a>
    ·
    <a href="https://github.com/Techypanda/UCP-Assignment-2019/issues">Report Bug</a>
    ·
    <a href="https://github.com/Techypanda/UCP-Assignment-2019/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)
* [Contact](#contact)
* [Acknowledgements](#acknowledgements)



<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][product-screenshot]](https://example.com)

We had to make tictactoe in c89.
**no memleaks and memerrors (100%)**


### Built With

* Editor: Atom/Vim
* Compiled With: GCC
* Makefile optional.



<!-- GETTING STARTED -->
## Getting Started

Clone this git repo
After compilation (via my attached makefile or through gcc commands), the program can be run through a unix commandline 
with the command ./TicTacToe FILENAME (there is attached testFiles in testFiles directory)

### Prerequisites

* gcc
```sh
gcc -Wall -Werror -pedantic -ansi -c board.c (OPTIONAL ARGUMENTS: -D SECRET=1 -D EDITOR=1)
gcc -Wall -Werror -pedantic -ansi -c commonlib.c (OPTIONAL ARGUMENTS: -D SECRET=1 -D EDITOR=1)
gcc -Wall -Werror -pedantic -ansi -c program.c (OPTIONAL ARGUMENTS: -D SECRET=1 -D EDITOR=1)
gcc -Wall -Werror -pedantic -ansi -c settings.c (OPTIONAL ARGUMENTS: -D SECRET=1 -D EDITOR=1)
gcc -Wall -Werror -pedantic -ansi -c userInterface.c (OPTIONAL ARGUMENTS: -D SECRET=1 -D EDITOR=1)
gcc -Wall -Werror -pedantic -ansi -c game.c (OPTIONAL ARGUMENTS: -D SECRET=1 -D EDITOR=1)
gcc -Wall -Werror -pedantic -ansi -c list.c (OPTIONAL ARGUMENTS: -D SECRET=1 -D EDITOR=1)
gcc -Wall -Werror -pedantic -ansi -c log.c (OPTIONAL ARGUMENTS: -D SECRET=1 -D EDITOR=1)
gcc board.o commonlib.o program.o settings.o userInterface.o game.o list.o log.o -o TicTacToe
```
* makefile
```make
make (OPTIONAL ARGUMENTS: -SECRET=1 -EDITOR=1)
```
<!--
### Installation
 
1. Clone the repo
```sh
git clone https://github.com/github_username/repo.git
```
2. Install NPM packages
```sh
npm install
```
-->


<!-- USAGE EXAMPLES -->
## Usage

Run it like so in a terminal window.
./TicTacToe FILE
File is a text file with m n k dimensions, as this is really M N K game.
If EDITOR is compiled with the program, you may edit MNK at runtime
if SECRET is compiled you lose a option in menu.

<!-- ROADMAP -->
<!--
## Roadmap

See the [open issues](https://github.com/github_username/repo/issues) for a list of proposed features (and known issues).


-->
<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Jonathan Wright - [@twitter_handle](https://twitter.com/techypanda2) - Twitter

Project Link: [https://github.com/Techypanda/UCP-Assignment-2019](https://github.com/Techypanda/UCP-Assignment-2019)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements

* myself
* me
* oh and I
* and maybe a little shoutout to my lecturer
* but again, it was me dio.




<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=flat-square
[contributors-url]: https://github.com/Techypanda/UCP-Assignment-2019/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=flat-square
[forks-url]: https://github.com/Techypanda/UCP-Assignment-2019/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=flat-square
[stars-url]: https://github.com/Techypanda/UCP-Assignment-2019/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=flat-square
[issues-url]: https://github.com/Techypanda/UCP-Assignment-2019/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=flat-square
[license-url]: https://github.com/Techypanda/UCP-Assignment-2019/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/jonathan-i-wright/
[product-screenshot]: images/screenshot.PNG
