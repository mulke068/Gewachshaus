FROM node:19.7.0-alpine3.17

WORKDIR /app

RUN apk update && apk upgrade
RUN apk add git

COPY ./package.json /app/

RUN npm install && npm cache clean --force

COPY . .

ENV PATH ./node_modules/.bin:$PATH