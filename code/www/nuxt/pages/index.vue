import { LazyNuxtLoadingIndicator } from '../.nuxt/components';

<template>
    <ClientOnly>
        <Home LazyNuxtLoadingIndicator="true"/>
    </ClientOnly>
</template>

<script setup>

definePageMeta({
    layout: 'home',
})
useHead({
    title: 'Home',
    meta: [
        { name: 'title', content: 'Home'},
        { name: 'keywords', content: 'Home , Main' },
        { property: 'og:site_name', content: 'Home' },
        { name: 'description', content: 'Dashboard für die Steuerung des Gewächshaus' },
        { name: "twitter:description", content: "Dashboard für die Steuerung des Gewächshaus"},
        { itemprop: 'description', content: 'Dashboard für die Steuerung des Gewächshaus' },
        { property: "og:description", content: "Dashboard für die Steuerung des Gewächshaus"}
    ]
})
</script>

<style scoped></style>