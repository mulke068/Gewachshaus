import { default } from './dashboard/index.vue';
<template>
    <div class="text-3xl text-black">
        <h1>Home</h1>
        <h2>Welcome Home</h2>

    </div>
</template>

<script setup>
definePageMeta({
    layout: 'default'
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