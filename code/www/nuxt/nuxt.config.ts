// https://nuxt.com/docs/api/configuration/nuxt-config
export default defineNuxtConfig({
  runtimeConfig: {
    public: {
      api_host: (process.env.NUXT_PUBLIC_API_HOST || "http://192.168.178.38:3030"), // default: http://localhost:8080
    }
  },
  // ...
  css: ["~/assets/css/main.css"],
  postcss: {
    plugins: {
      tailwindcss: {},
      autoprefixer: {},
    },
  },
  nitro: {},
  /*
  server: {
    port: 8000, // default: 3000
    host: '0.0.0.0', // default: localhost,
    timing: false
  },
  */
  components: true,
});
