import { ContentDoc } from '../../.nuxt/components';
<template>
    <main class="p-4">
        <ContentDoc />
    </main>
</template>

<style scoped>
main :deep(h1) {
  @apply text-4xl font-bold mb-4;
}

main :deep(h2) {
  @apply text-2xl font-bold mb-2;
}

main :deep(h3) {
  @apply text-xl font-bold mb-2;
}

main :deep(h4) {
  @apply text-lg font-bold mb-2;
}

main :deep(h5) {
  @apply text-base font-bold mb-2;
}

main :deep(h6) {
  @apply text-sm font-bold mb-2;
}

main :deep(p) {
  @apply mb-4;
}

main :deep(ul),
main :deep(ol) {
  @apply ml-6 mb-4;
}

main :deep(li) {
  @apply list-disc;
}

main :deep(a) {
  @apply text-minsk-500 hover:underline;
}

main :deep(table) {
  @apply w-full border-collapse;
}

main :deep(th),
main :deep(td) {
  @apply border p-2;
}

main :deep(code) {
  @apply bg-gray-100 p-1 rounded dark:bg-gray-900;
}

main :deep(pre) {
  @apply bg-gray-100 p-4 mb-4 dark:bg-gray-900;
}

main :deep(blockquote) {
  @apply border-l-4 pl-4 italic text-gray-600 dark:text-gray-400;
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
