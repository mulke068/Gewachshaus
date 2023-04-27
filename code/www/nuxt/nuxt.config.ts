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
      meta: [
        /*
          Primary Meta Tags
        */
        { charset: "utf-8" },
        { rel: "icon", type: "image/x-icon", href: "/favicon.ico"},
        { name: "viewport", content: "width=device-width,initial-scale=1" },
        { name: "author", content: "Mulke068"},
        { name: "theme-color", content: "#ffffff" },
        { name: "theme-color", content: "#000000" },
        /*
          Robots & Google Tags
        */
        //{ name: 'robots', content: 'index, follow' },
        //{ name: 'googlebot', content: 'index, follow' },
        //{ name: 'google', content: 'nositelinkssearchbox' },
        { name: 'google', content: 'notranslate' },
        //{ name: 'format-detection', content: 'telephone=no' },
        //{ name: 'msapplication-tap-highlight', content: 'no' },
        /*
          OG Tags
        */
        { name: "og:title", content: "Gewachshaus"},
        { name: "og:description", content: "Das Gewachshaus Dashboard für die Steuerung des Gewachshauses"},
        { name: "og:type", content: "website"},
        { name: "og:url", content: "https://www.kevbchef.com"},
        { name: "og:image", content: "https://www.kevbchef.com/img/logo_1024x1024.png"},
        { name: "og:locale", content: "de_DE"},
        { name: "og:locale:alternate", content: "lu_LU"},
        { name: "og:locale:alternate", content: "en_US"}
      ],
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
