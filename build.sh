#!/usr/bin/env bash
echo "Start Building Website"
cd /home/$USER/Gewachshaus/code/www/nuxt
sudo npm i
sudo npm run build
echo "Website Builded"
echo "Start Building API"
cd /home/$USER/Gewachshaus/code/www/api
sudo npm i
sudo npm run build
echo "API Builded"
