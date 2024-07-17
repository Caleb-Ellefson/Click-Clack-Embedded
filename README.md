<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">



<h1 align="center">Split-Flap Clock</h3>
      <img src='./src/assets/main.png' >
  <p align="center">
    Full Stack Embedded project using React, C++, and NodeJS
    <br />
    <br />
    <br />
    ·
    <a href="https://github.com/Caleb-Ellefson/Click-Clack-Embedded/issues">Report Bug</a>
    ·
    <a href="https://github.com/Caleb-Ellefson/Click-Clack-Embedded/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project
<p align=center>
 ![til](./src/assets/video1.gif)
</p>

Split-Flap Clock Project Overview

The overall project came together quite well. I created a split-flap clock using 3D printed parts, a skateboard truck bearing, a magnet, a hall sensor, and an RTC module to keep track of the time. Although there were a few minor complications with sending JSON data from the Node server to the ESP8266 via a GET request and creating a flag and interrupt to manage the loop, I was able to overcome these challenges.
Project Details
Front-End and Server Setup

I built a simple front-end with React and a Node.js server. Using a library called concurrently, I hosted both the server and the front-end webpage simultaneously. The webpage includes a form that sends a POST request to the server, storing JSON data for functionalities like setting the time, creating an alarm, and turning the clock on and off. This data is stored in a variable on the server.
ESP8266 Functionality

Every 5 seconds, the ESP8266 sends a GET request to the server to retrieve this data. The ESP8266 operates using two main functions: setup and loop.
Setup Function

The setup function connects the ESP8266 to WiFi and configures the speed and acceleration of the stepper motors. It also calls stepper_begin(), which in turn calls calibration(). The calibration function uses a hall sensor, which detects polarity and outputs a boolean value. By gluing a magnet to the main crank gear, the sensor can measure full revolutions of the clock or gears, ensuring a 1:1 gear ratio.
Loop Function

The loop function runs continuously, managing the clock's operation based on the data received from the server.
Coding Complications

    ESP8266 GET Request Issue:
        Problem: The ESP8266 could not make a GET request directly to the server via localhost (e.g., https://localhost/api:5100). Although the request worked using Thunder Client (a CRUD VSCode extension), the ESP8266 returned a -1 HTTP error code.
        Solution: I used the ifconfig command on my Linux Mint machine to find the IPv6 address and used that as the server address for the request. This issue was likely due to security settings on the school WiFi, which kept certain ports closed.

    Creating a Flag and Interrupt:
        Problem: Since the setup function runs only once per power cycle and the loop function runs continuously, I needed a way to call a function only once within the loop.
        Solution: I created a boolean variable as a flag. By implementing simple logic, I ensured the function only ran when the flag was false. This involved creating an interrupt, a common technique in embedded systems, although it was new to me.

Project Insights

Overall, this project was a great learning experience. I gained valuable skills in 3D printing, modeling, embedded software, and project management. While there were many things I could have done differently to save time, the process of troubleshooting and resolving issues with both code and hardware taught me a lot. I approached the project with the goal of challenging myself, and I definitely achieved that.
Conclusion

This project taught me the importance of perseverance and problem-solving in both software and hardware contexts. I’ve attached some pictures of the assembled 3D model I created using AutoFusion 360 for your reference.

<div width= 100%>
  <img src='./src/assets/back.png' alt="Back view of the clock" style="width: 300px; display: inline-block; margin-right: 10px;">
  <img src='./src/assets/main.png' alt="Main view of the clock" style="width: 300px; display: inline-block; margin-right: 10px;">
  <img src='./src/assets/side.png' alt="Side view of the clock" style="width: 300px; display: inline-block;">
</div>

### Built With

* [![React][React.js]][React-url]
* [![C++][c++]][C++-url]
* [![Node.js][node.js]][node-url]
* [![Express.js][express.js]][express-url]




<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Caleb Ellefson - calebroger@gmail.com

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Random Nerd tutorials](https://randomnerdtutorials.com/esp8266-nodemcu-http-get-post-arduino/)


<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/Caleb-Ellefson/Click-Clack-Embedded.svg?style=for-the-badge
[contributors-url]: https://github.com/Caleb-Ellefson/Click-Clack-Embedded/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Caleb-Ellefson/Click-Clack-Embedded.svg?style=for-the-badge
[forks-url]: https://github.com/Caleb-Ellefson/Click-Clack-Embedded/network/members
[stars-shield]: https://img.shields.io/github/stars/Caleb-Ellefson/Click-Clack-Embedded.svg?style=for-the-badge
[stars-url]: https://github.com/Caleb-Ellefson/StratRoulette
[issues-shield]: https://img.shields.io/github/issues/Caleb-Ellefson/Click-Clack-Embedded.svg?style=for-the-badge
[issues-url]: https://github.com/Caleb-Ellefson/StratRoulette/issues
[license-shield]: https://img.shields.io/github/license/Caleb-Ellefson/Click-Clack-Embedded.svg?style=for-the-badge
[license-url]: https://github.com/Caleb-Ellefson/Click-Clack-Embedded/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/caleb-ellefson/
[product-screenshot]: client/src/assets/images/screenshot.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[C++]:https://img.shields.io/badge/-C++-blue?logo=cplusplus
[C++-url]:https://learn.microsoft.com/en-us/cpp/?view=msvc-170
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com
[mongo.js]: https://img.shields.io/badge/MongoDb-Mongodb?style=for-the-badge&logo=mongodb&labelColor=black
[mongo-url]:https://www.mongodb.com/
[node.js]:https://img.shields.io/node/v/passport?style=for-the-badge
[node-url]:https://nodejs.org/en
[express.js]:https://img.shields.io/npm/l/express?style=for-the-badge&logo=express&label=express
[express-url]:https://expressjs.com/
