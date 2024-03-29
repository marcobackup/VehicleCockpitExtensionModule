<p align="center">
    <strong>Vehicle cockpit extension module</strong> (VCEM) is an additional vehicle's CAN node working on low speed B-CAN (50kbit/s) that processes and shows car parameters and faults.
</p>
<p align="center">
    <a target="_blank"><img href="https://en.wikipedia.org/wiki/C%2B%2B" src="https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white"/></a>    
    <a target="_blank"><img href="https://en.wikipedia.org/wiki/C_(programming_language)" src="https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white"/></a>   
    <a target="_blank" href=""><img href="https://www.qt.io/" src="https://img.shields.io/badge/Qt-%23217346.svg?style=for-the-badge&logo=Qt&logoColor=white"/></a>
    <a target="_blank" href="https://en.wikipedia.org/wiki/Linux_on_embedded_systems"><img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black"/></a>
    <a target="_blank" href="https://www.figma.com/"><img src="https://img.shields.io/badge/figma-%23F24E1E.svg?style=for-the-badge&logo=figma&logoColor=white"/></a> 
    
</p>
<p align="center">
    <a target="_blank" href="https://www.youtube.com/channel/UC29L1qjXSVCqUSbJK69ms-Q"><img height="20" src="https://img.shields.io/badge/YouTube-%23FF0000.svg?style=for-the-badge&logo=YouTube&logoColor=white" /></a>
    <a target="_blank" href="https://www.linkedin.com/in/marco-sgr%C3%B2"><img height="20" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" /></a>
</p>

<h1 align="center">
  <a href="https://github.com/marcobackup/VehicleCockpitExtensionModule/">
    <img src="https://github.com/marcobackup/VehicleCockpitExtensionModule/blob/main/docs/UIScreenshot/homeRed.png?raw=true" alt="VCEM">
  </a>

  <table>
    <tr>
      <td>
        <img src="https://github.com/marcobackup/VehicleCockpitExtensionModule/blob/main/docs/UIScreenshot/homeBlue.png?raw=true" alt="VCEM">
      </td>
      <td>  
        <img src="https://github.com/marcobackup/VehicleCockpitExtensionModule/blob/main/docs/UIScreenshot/homeGold.png?raw=true" alt="VCEM">
      </td>
      <td>
        <img src="https://github.com/marcobackup/VehicleCockpitExtensionModule/blob/main/docs/UIScreenshot/homeSilver.png?raw=true" alt="VCEM">
      </td>
    </tr>
  </table>
</h1>


<p align="center">
<a href="#introduction">Introduction</a> &nbsp;&bull;&nbsp;
<a href="#installation">Diagram</a> &nbsp;&bull;&nbsp;
<a href="#usage">Usage</a> &nbsp;&bull;&nbsp;
<a href="#issue">Question?</a>
</p>

## Introduction
This project was born from the idea of ​​being able to make the parameters of a vehicle accessible, including some that the manufacturer often does not show on the **IPC**.

In short, the system consists of two main parts: a **microcontroller unit** (MCU) and a **microprocessor unit / system on chip** (MCU / SoC).

The **MCU** is responsible for **sniffing the packets** from the low speed B-CAN bus, **processing** them and when necessary **updating the EEPROM** with the system settings.
The **processed CAN packets** and the **system settings** are **sent** to the MPU / SoC.
It also reads incoming data from the MPU / SoC.

Instead, the **MPU / SoC** takes care of deserializing the can frames and **displaying** them on a UI built with qt creator or **starting some system routines**.

The **transmission protocol** used between units is **UART**.

## Diagram
Here's a diagram to explain the system workflow.
<h1 align="center">
  <a href="https://github.com/marcobackup/VehicleCockpitExtensionModule/">
    <img src="https://github.com/marcobackup/VehicleCockpitExtensionModule/blob/main/docs/VCEMDiagramWorkflow.png?raw=true" alt="VCEM">
  </a>
</h1>

## Usage
You can currently watch a demonstration video
https://youtube.com/shorts/YbyWsrBbebo?si=RZkPqH19X9Clxu5W
_In updating..._

## Question?
Please, feel free to ask questions if something is unclear or you want to learn more. 
This project is constantly updated so if something is wrong please let me know!
