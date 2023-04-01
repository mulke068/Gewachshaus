FROM node:18.15.0-alpine3.17

# Create app directory
WORKDIR /api

# Install app dependencies
COPY ./package*.json /api

RUN npm install
#RUN npx tsc
RUN npm cache clean --force

# Bundle app source
COPY . .
