
<template>
    <ClientOnly>
        <NuxtLoadingIndicators />
        <Home />
    </ClientOnly>
</template>

<script setup>

definePageMeta({
    layout: 'home',
})
useHead({
    title: 'Home',
    meta: [
        { name: 'keywords', content: 'Home , Main' },
        { property: 'og:site_name', content: 'Home' },
    ]
})
</script>

<style scoped></style>