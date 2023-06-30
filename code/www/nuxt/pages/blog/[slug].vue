import { ContentDoc } from '../../.nuxt/components';
<template>
    <main>
        <ContentDoc />
    </main>
</template>


<style scoped>
main {
    @apply p-4 
}
main :deep(h1) {
    @apply text-2xl p-4
}
main :deep(h2) {
    @apply text-lg p-2
}

</style>

<script setup>
const route = useRoute()
const site = route.params.slug
useHead({
    title: `${site}`,
    meta: [
        { name: 'title', content: `${site}`},
        { name: 'keywords', content: 'Dcoument , Descriptrion' },
        { property: 'og:site_name', content: `${site}` },
        { name: 'description', content: `Documentation from ${site}` },
        { name: "twitter:description", content: `Documentation from ${site}` },
        { itemprop: 'description', content: `Documentation from ${site}` },
        { property: "og:description", content: `Documentation from ${site}` }
    ]
})
</script>
