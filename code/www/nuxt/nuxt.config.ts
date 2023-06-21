// https://nuxt.com/docs/api/configuration/nuxt-config
export default defineNuxtConfig({
  runtimeConfig: {
    public: {
      api_host: (process.env.NUXT_PUBLIC_API_HOST || "http://localhost:8080"), // default: http://localhost:8080
    }
  },
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
        { name: "generator", content: "NuxtJS"},
        { name: "theme-color", content: "#ffffff" },
        { name: "theme-color", content: "#000000" },
        /*
          Robots Tags
        */
        //{ name: 'robots', content: 'index, follow' },
        //{ name: 'format-detection', content: 'telephone=no' },
        //{ name: 'msapplication-tap-highlight', content: 'no' },
        /*
          OG Tags
        */
        { property: "og:title", content: "Gewachshaus"},
        { property: "og:description", content: "Dashboard für die Steuerung des Gewachshauses"},
        { property: "og:type", content: "website"},
        { property: "og:url", content: "https://www.kevbchef.com"},
        { property: "og:image", content: "https://www.kevbchef.com/img/logo_1024x1024.png"},
        { property: "og:image:type", content: "image/png"},
        { property: 'og:image:width', content: '1024'},
        { property: 'og:image:height', content: '1024'},
        { property: "og:locale", content: "de_DE"},
        { property: "og:locale:alternate", content: "lu_LU"},
        { property: "og:locale:alternate", content: "en_US"},
        /*
          Google Tags
        */
        //{ name: 'googlebot', content: 'index, follow' },
        //{ name: 'google', content: 'nositelinkssearchbox' },
        { name: 'google', content: 'notranslate' },
        { itemprop: 'name', content: 'Gewachshaus' },
        { itemprop: 'description', content: 'Dashboard für die Steuerung des Gewachshauses' },
        { itemprop: 'image', content: 'https://www.kevbchef.com/img/logo_1024x1024.png'},
        /*
          Twitter Tags
        */
        //{ name : "twitter:creator", content: "@Mulke068"},
        //{ name: "twitter:site", content: "@Mulke068"},
        { name: "twitter:card", content: "summary_large_image"},
        { name: "twitter:title", content: "Gewachshaus"},
        { name: "twitter:description", content: "Dashboard für die Steuerung des Gewachshauses"},
        { name: "twitter:url", content: "https://www.kevbchef.com"},
        { name: "twitter:domain", content: "kevbchef.com"},
        { name: "twitter:image", content: "https://www.kevbchef.com/img/logo_1024x1024.png"},
        { name: "twitter:image:src", content: "https://www.kevbchef.com/img/logo_1024x1024.png"},
        { name: "twitter:image:type", content: "image/png"},
        { name: 'twitter:image:width', content: '1024'},
        { name: 'twitter:image:height', content: '1024'},
        { name: "twitter:image:alt", content: "Gewachshaus Logo"},
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
