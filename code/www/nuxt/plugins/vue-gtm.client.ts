import { createGtm } from '@gtm-support/vue-gtm'
import { useRouter } from 'vue-router'

export default defineNuxtPlugin((nuxtApp) => {
    nuxtApp.vueApp.use(createGtm({
        id: 'GTM-5ZZBP54',
        defer: false,
        compatibility: false,
        enabled: true,
        debug: true,
        loadScript: true,
        vueRouter: useRouter(),
        trackOnNextTick: false,
    }))
})