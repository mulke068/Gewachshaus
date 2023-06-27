import { Link } from '../../.nuxt/components';
<template>
<div class="container p-4 mx-auto">
  <div class="items-center justify-center md:flex md:flex-col header ">
    <div class="p-4 text-center">
      <img src="/img/GewächshausLogo_LPEM_1024x1024.png" title="LPEM LOGO" alt="LPEM LOGO" width="150" height="150" />
    </div>
    <table>
      <tr>
        <td>
          <img src="/img/GewächshausLogo_LPEM_2_1024x1024.png" width="70" height="70" />
        </td>
        <td>
          <h2>&copy;2023</h2>
        </td>
        <div class="p-4 text-center md:flex">
          <img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/mulke068/Gewachshaus?color=blue&logo=Gewachshaus&logoColor=red" />
          <img alt="GitHub" src="https://img.shields.io/github/license/mulke068/Gewachshaus" />
          <img alt="GitHub tag (latest by date)" src="https://img.shields.io/github/v/tag/mulke068/Gewachshaus" />
          <img alt="GitHub release (latest by date)" src="https://img.shields.io/github/v/release/mulke068/Gewachshaus?display_name=tag" />
        </div>
      </tr>
    </table>
  </div>
  <div class="content">
    <h1 class="text-4xl">All Docs</h1>
    <a href="blog/www" class="underline">www</a>
    <ul>
      <a href="blog/nuxt" class="underline">Website</a>
    </ul>
    <ul>
      <a href="blog/api" class="underline">API</a>
    </ul>
    <a href="blog/application" class="underline">application</a>
    <br />
    <a href="blog/esp32_display" class="underline">ESP Display</a>
    <br />
    <a href="blog/esp32_sensor" class="underline">ESP SENSORS</a>
    <h1 class="text-4xl">Stellungsannahme</h1>
    <h2 class="text-2xl">Plexiglas</h2>
    <ul class="pl-8 list-disc">
      <li>max Größe 600x400 m^2</li>
      <li>transparent or milch</li>
      <li>3mm or 5mm</li>
    </ul>
    <h2 class="text-2xl">Hauptversorgung</h2>
    <ul class="pl-8 list-disc">
      <li>Netzteil</li>
      <li>Solarpannel + Speicher</li>
      <li>MAX 12v</li>
      <li>Über Solarpannel soll die Beleuctung versorgt werden</li>
    </ul>
    <h2 class="text-2xl">Arduino oder Raspberry PI</h2>
    <h3 class="text-xl">Sensoren</h3>
    <ul class="pl-8 list-disc">
      <li>Temperatur</li>
      <li>Luftfeuchtigket</li>
    </ul>
    <h3 class="text-xl">Aktoren</h3>
    <ul class="pl-8 list-disc">
      <li>Lcd 16x2</li>
      <li>Beleuchtung</li>
      <li>Belüftung</li>
    </ul>
    <h2 class="text-2xl">Zusatz function</h2>
    <p>Raspberry Pi für Visualiesierung auf einem lcd angeschlossen</p>
    <h1 class="text-4xl">Dossiert</h1>
    <h2 class="text-2xl">1. Funktionsbeschriebung</h2>
    <ul class="pl-8 list-disc">
      <li>Text</li>
      <li>Animation</li>
    </ul>
    <h2 class="text-2xl">2. Materialliste</h2>
    <ul class="pl-8 list-disc">
      <li>Peris Liste in Exel</li>
    </ul>
    <h2 class="text-2xl">3. Elektrik</h2>
    <ul class="pl-8 list-disc">
      <li>Schaltplan</li>
      <li>Synoptik</li>
      <li>Programm (code vom Arduino)</li>
    </ul>
    <h2 class="text-2xl">4. Gehäuse</h2>
    <ul class="pl-8 list-disc">
      <li>Fusion Model erstellen vom Gesammt Projeckt</li>
      <li>3D Model Animation (in ppt)</li>
    </ul>
  </div>
  <div class="bottom">
    <div>
      <h1 class="mb-4 text-2xl font-bold">Links</h1>
      <h2 class="mb-2 text-xl font-bold">Shops</h2>
      <ul class="mb-4">
        <li><a href="https://www.az-delivery.de" target="_blank" class="text-blue-500 hover:underline">AZ Delivery</a></li>
        <li><a href="https://www.reichelt.de" target="_blank" class="text-blue-500 hover:underline">Reichelt</a></li>
        <li><a href="https://de.elv.com" target="_blank" class="text-blue-500 hover:underline">ELV</a></li>
        <li><a href="https://lemo-solar.de" target="_blank" class="text-blue-500 hover:underline">Lemo-Solar</a></li>
        <li><a href="https://www.electronic-shop.lu" target="_blank" class="text-blue-500 hover:underline">Electronic-Shop</a></li>
      </ul>
      <h2 class="mb-2 text-xl font-bold">Others</h2>
      <ul class="mb-4">
        <li><a href="http://projects.htl-klu.at/Projekt_1617/pr7abeli35331/Internet/details.html" target="_blank" class="text-blue-500 hover:underline">link 1</a></li>
        <li><a href="https://randomnerdtutorials.com/esp32-http-get-post-arduino/" target="_blank" class="text-blue-500 hover:underline">link 2</a></li>
        <li><a href="https://randomnerdtutorials.com/getting-started-node-red-dashboard/" target="_blank" class="text-blue-500 hover:underline">link 3</a></li>
        <li><a href="https://www.instructables.com/Automated-Greenhouse/" target="_blank" class="text-blue-500 hover:underline">link 4</a></li>
      </ul>
      <ul class="mb-4">
        <li><a href="http://www.barth-dev.de/online/rgb565-color-picker/" target="_blank" class="text-blue-500 hover:underline">color picker</a></li>
        <li><a href="https://github.com/jiteshsaini/rest-api-examples" target="_blank" class="text-blue-500 hover:underline">Github 1</a></li>
      </ul>
      <h2 class="mb-2 text-xl font-bold">Videos</h2>
      <ul class="mb-4">
        <li><a href="https://www.youtube.com/watch?v=1J8-cBR0R3M" target="_blank" class="text-blue-500 hover:underline">video 1</a></li>
      </ul>
      <h2 class="mb-2 text-xl font-bold">Essential</h2>
      <ul class="mb-4">
        <li><a href="https://javl.github.io/image2cpp/" target="_blank" class="text-blue-500 hover:underline">Converter BMP into C</a></li>
      </ul>
    </div>
  </div>
</div>
</template>