import { Link } from '../../.nuxt/components';
<template>
<div class="container p-4 mx-auto">
  <div class="flex flex-col items-center justify-center header ">
	  <video class="w-auto aspect-video" alt="Gewächshaus Intro LPEM (EMH Music | Electro - Minimal - House)" autoplay muted>
		  <source src="/video/intro.mp4" srcset="/img/logo-gewächshaus-lpem_1024x1024.png" type="video/mp4">
	  </video>
    <div class="p-4 text-center">
      <img src="/img/logo-gewächshaus-lpem_1024x1024.png" alt="Gewächshaus Logo LPEM" width="150" height="150" />
    </div>
    <table class="bg-gray-300 ">
      <tr>
        <td>
          <img src="/img/logo2-gewächshaus-lpem_1024x1024.png" alt="Gewächshaus Logo 2 LPEM" width="70" height="70" />
        </td>
        <td>
          <h2>&copy;2023</h2>
        </td>
        <div class="p-4 text-center md:flex">
          <img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/mulke068/Gewachshaus?color=blue&logo=Gewachshaus&logoColor=red" />
          <img alt="GitHub" src="https://img.shields.io/github/license/mulke068/Gewachshaus" />
          <img alt="GitHub tag (latest by date)" src="https://img.shields.io/github/v/tag/mulke068/Gewachshaus" />
          <img alt="GitHub release (latest by date)" src="https://img.shields.io/github/v/release/mulke068/Gewachshaus?display_name=tag" />
          <img alt="GitHub pages-build-deploayment" src="https://github.com/mulke068/Gewachshaus/actions/workflows/pages/pages-build-deployment/badge.svg">
        </div>
      </tr>
    </table>
  </div>
  <div class="content">
    <div class="container py-8 mx-auto">
      <h1 class="mb-4 text-3xl font-bold">Alle Documente</h1>

      <ul class="mb-6 ml-6 list-disc">
        <li>
          <a href="blog/www" class="text-blue-500 hover:underline">www</a>
          <ul class="ml-6 list-disc">
            <li><a href="blog/website" class="text-blue-500 hover:underline">Website</a></li>
            <li><a href="blog/api" class="text-blue-500 hover:underline">API</a></li>
          </ul>
        </li>
        <li>
          <a href="blog/application" class="text-blue-500 hover:underline">application</a>
          <ul class="ml-6 list-disc">
            <li><a href="blog/esp32_display" class="text-blue-500 hover:underline">ESP Display</a></li>
            <li><a href="blog/esp32_sensor" class="text-blue-500 hover:underline">ESP Sensor</a></li>
          </ul>
        </li>
      </ul>
    
      <h2 class="mb-4 text-2xl font-bold">Richtlinien</h2>
    
      <h3 class="mb-2 text-xl font-bold">Plexiglas</h3>
      <ul class="mb-4 ml-6 list-disc">
        <li>max. Größe 600x400 m^2</li>
        <li>transparent- oder Milchglas</li>
        <li>3mm oder 5mm</li>
      </ul>
    
      <h3 class="mb-2 text-xl font-bold">Hauptversorgung</h3>
      <ul class="mb-4 ml-6 list-disc">
        <li>Netzteil</li>
        <li>MAX 12v</li>
        <li>PV-Anlage + Speicher</li>
        <li>Über PV-Anlage soll die Beleuchtung versorgt werden</li>
      </ul>
    
      <h3 class="mb-2 text-xl font-bold">Arduino oder Raspberry PI</h3>
    
      <h4 class="mb-2 text-lg font-bold">Sensoren</h4>
      <ul class="mb-4 ml-6 list-disc">
        <li>Temperatur</li>
        <li>Luftfeuchtigkeit</li>
      </ul>
    
      <h4 class="mb-2 text-lg font-bold">Aktoren</h4>
      <ul class="mb-4 ml-6 list-disc">
        <li>Lcd 16x2</li>
        <li>Beleuchtung</li>
        <li>Belüftung</li>
      </ul>
    
      <h4 class="mb-2 text-lg font-bold">Zusatz Funktionen</h4>
      <ul class="mb-4 ml-6 list-disc">
        <li>Raspberry Pi für Visualisierung auf einem lcd angeschlossen</li>
      </ul>
    
      <h2 class="mb-4 text-2xl font-bold">Dossier</h2>
    
      <ol class="mb-6 ml-6 list-decimal">
        <li>
          Funktionsbeschreibung
          <ul class="ml-6 list-disc">
            <li>Text</li>
            <li>Animation</li>
          </ul>
        </li>
        <li>
          Materialliste
          <ul class="ml-6 list-disc">
            <li>Preis Liste in Excel</li>
          </ul>
        </li>
        <li>
          Elektrik
          <ul class="ml-6 list-disc">
            <li>Schaltplan</li>
            <li>Synoptik</li>
            <li>Programm (code vom Arduino)</li>
          </ul>
        </li>
        <li>
          Gehäuse
          <ul class="ml-6 list-disc">
            <li>Fusion Model erstellen vom Gesamtprojekt</li>
            <li>3D Model Animation (in ppt)</li>
          </ul>
        </li>
      </ol>
    
      <h2 class="mb-4 text-2xl font-bold">Links</h2>
    
      <h3 class="mb-2 text-xl font-bold">Geschäfte</h3>
      <ul class="mb-4 ml-6 list-disc">
        <li><a href="https://www.az-delivery.de/" class="text-blue-500 hover:underline">AZ-Delivery.de</a></li>
        <li><a href="https://www.reichelt.de/" class="text-blue-500 hover:underline">Reichelt.de</a></li>
        <li><a href="https://www.elv.com/" class="text-blue-500 hover:underline">ELV.com</a></li>
        <li><a href="https://www.lemo-solar.de/" class="text-blue-500 hover:underline">Lemo-Solar.de</a></li>
        <li><a href="https://www.electronic-shop.lu/" class="text-blue-500 hover:underline">Electronic-Shop.lu</a></li>
        <li><a href="https://www.conrad.de/" class="text-blue-500 hover:underline">Conrad.de</a></li>
      </ul>
    
      <h3 class="mb-2 text-xl font-bold">Anderes</h3>
      <ul class="mb-4 ml-6 list-disc">
        <li><a href="http://projects.htl-klu.at/Projekt_1617/pr7abeli35331/Internet/details.html" class="text-blue-500 hover:underline">link 1</a></li>
        <li><a href="https://randomnerdtutorials.com/esp32-http-get-post-arduino/" class="text-blue-500 hover:underline">link 2</a></li>
        <li><a href="https://randomnerdtutorials.com/getting-started-node-red-dashboard/" class="text-blue-500 hover:underline">link 3</a></li>
        <li><a href="https://www.instructables.com/Automated-Greenhouse/" class="text-blue-500 hover:underline">link 4</a></li>
        <li><a href="http://www.barth-dev.de/online/rgb565-color-picker/" class="text-blue-500 hover:underline">color piker</a></li>
        <li><a href="https://github.com/jiteshsaini/rest-api-examples" class="text-blue-500 hover:underline">Github 1</a></li>
      </ul>
    
      <h3 class="mb-2 text-xl font-bold">Videos</h3>
      <ul class="mb-4 ml-6 list-disc">
        <li><a href="https://www.youtube.com/watch?v=1J8-cBR0R3M" class="text-blue-500 hover:underline">video 1</a></li>
      </ul>
    
      <h3 class="mb-2 text-xl font-bold">Essential</h3>
      <ul class="mb-4 ml-6 list-disc">
        <li><a href="https://javl.github.io/image2cpp/" class="text-blue-500 hover:underline">Converter BMP into C</a></li>
      </ul>
    
      <h2 class="mb-4 text-2xl font-bold">License</h2>
      <p class="mb-4">
        <a href="blog/license" class="text-blue-500 hover:underline">License Terms</a>
      </p>
      <p class="text-gray-600 bg-gray-100 dark:bg-gray-900 dark:text-gray-400">
        &copy; 2023 the original author or authors.
      </p>
      <p class="mb-4">
        Licensed under the Apache License, Version 2.0 (the "License");
        you may not use this file except in compliance with the License.
        You may obtain a copy of the License at
      </p>
      <p class="text-gray-600 bg-gray-100 dark:bg-gray-900 dark:text-gray-400">
        <a href="http://www.apache.org/licenses/LICENSE-2.0" class="text-blue-500 hover:underline">http://www.apache.org/licenses/LICENSE-2.0</a>
      </p>
      <p class="mb-4">
        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
      </p>
    </div>
  </div>
</div>
</template>
