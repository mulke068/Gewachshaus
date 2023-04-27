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
        { name: 'description', content: 'Show all the sensor data'},
        { name: 'keywords', content: 'sensor, data'},
        { name: 'og:site_name', content: 'Sensor Data'}
    ]
})
</script>

<style>

</style>