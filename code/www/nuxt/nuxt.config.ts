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
  loading: {
    name: "circle",
    color: "#3B8070",
    background: "white",
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
  app: {
    head: {
      script: [
          {
              src: 'https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js?client=ca-pub-5201653139270385',
              async: true,
              crossorigin: 'anonymous'
          },
          {
              src: 'https://www.googletagmanager.com/gtag/js?id=G-QL29HF54EY',
              async: true,
          }, 
          {
              innerHTML: `
                  window.dataLayer = window.dataLayer || [];
                  function gtag(){dataLayer.push(arguments);}
                  gtag('js', new Date());

                  gtag('config', 'G-QL29HF54EY');
              `,
              type: 'text/javascript',
          }
      ],
    }
  },
});
