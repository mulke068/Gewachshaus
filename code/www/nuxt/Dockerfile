FROM node:18.15.0-alpine3.17

WORKDIR /nuxt

RUN apk update && apk upgrade
RUN apk add git

COPY ./package*.json /nuxt

RUN npm install && npm cache clean --force

COPY . .

#RUN npm run build

ENV PATH ./node_modules/.bin:$PATH