// https://nuxt.com/docs/api/configuration/nuxt-config
export default defineNuxtConfig({
  runtimeConfig: {
    public: {
      api_host: (process.env.NUXT_PUBLIC_API_HOST || "http://192.168.178.38:3030"), // default: http://localhost:8080
      /*
      'google-adsense': {
        id: (process.env.GOOGLE_ADSENSE_ID || 'ca-pub-5201653139270385'),
        test: process.env.GOOGLE_ADSENSE_TEST_MODE === 'true'
      }
      */
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
  mdoules: [
    ["@nuxtjs/google-adsense"]
  ],
  'google-adsense': {
    id: "ca-pub-5201653139270385",
    //onPageLoad: false,
    //pageLevelAds: false,
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
