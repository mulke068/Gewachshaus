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
    meta: [
        { name: 'title', content: 'Home'},
        { name: 'description', content: 'Dashboard für die Steuerung des Gewachshaus' },
        { name: 'keywords', content: 'Home , Main' },
        { property: 'og:site_name', content: 'Home' },
    ]
})
</script>

<style scoped></style>