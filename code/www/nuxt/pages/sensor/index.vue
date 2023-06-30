import { Title } from '../../.nuxt/components';

<template>
    <div>
        <div class="container">
            <div class="flex justify-center p-5 text-3xl">Sensor Data</div>
            <NuxtErrorBoundary>
                <Sensor />
                <template #error="{ error }">
                    <div class="p-5 text-center text-gray-500 text-2l">
                        Die Daten konnten nicht geladen werden.
                        <br>
                        {{ error }}
                    </div>
                </template>
            </NuxtErrorBoundary>
        </div>
    </div>
</template>

<script setup>
definePageMeta({
    layout: 'default',
})

useHead({
    title: 'Sensor Data',
    meta: [
        { name: 'title', content: 'Sensor Data'},
        { property: 'og:site_name', content: 'Sensor Data'},
        { name: 'keywords', content: 'sensor, data'},
        { name: "description", content: 'Zeigt alle Sensor Daten'},
        { name: "twitter:description", content: "Zeigt alle Sensor Daten"},
        { itemprop: "description", content: 'Zeigt alle Sensor Daten' },
        { property: "og:description", content: "Zeigt alle Sensor Daten"}
    ]
})
</script>

<style>

</style>