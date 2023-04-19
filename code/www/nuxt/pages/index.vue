
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
        { name: 'description', content: 'Home Page'},
        { name: 'keywords', content: 'home, page' }
    ]
})
</script>

<style scoped></style>