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