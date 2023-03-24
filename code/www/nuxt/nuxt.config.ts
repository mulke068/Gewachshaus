// https://nuxt.com/docs/api/configuration/nuxt-config
export default defineNuxtConfig({
  // ...
  css: ["~/assets/css/main.css"],
  postcss: {
    plugins: {
      tailwindcss: {},
      autoprefixer: {},
    },
  },
  //nitro: {},
  server: {
    port: 8000, // default: 3000
    host: '0.0.0.0', // default: localhost,
    timing: false
  },
  components: true,
});
