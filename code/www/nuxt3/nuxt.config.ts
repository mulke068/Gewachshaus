// https://nuxt.com/docs/api/configuration/nuxt-config
export default defineNuxtConfig({
    pages: true,
    app: {
        pageTransition: {
          name: 'fade',
          mode: 'out-in' // default
        },
        layoutTransition: {
          name: 'slide',
          mode: 'out-in' // default
        }
      }
})
