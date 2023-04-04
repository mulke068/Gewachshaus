FROM node:18.15.0-alpine3.17

# Create app directory
WORKDIR /api

# Install app dependencies
COPY ./package*.json /api

# Install app dependencies
RUN npm install
RUN npm cache clean --force

# Bundle app sourcce
COPY . .
