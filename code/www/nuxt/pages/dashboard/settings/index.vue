<template>
    <div class="container">
        <h1 class="flex justify-center p-5 text-3xl ">Settings</h1>
        <NuxtErrorBoundary >
            <Settings />
            <template #error="{ error }">
                <div class="p-5 text-center text-gray-500 text-2l">
                    Die Daten konnten nicht geladen werden.
                    <br>
                    {{ error }}
                </div>
            </template>
        </NuxtErrorBoundary>
    </div>
</template>

<script lang="ts" setup>
definePageMeta({
        layout: 'default'
    })
useHead({
    title: 'Settings',
    meta: [
        { name: 'title', content: 'Settings'},
        { name: 'keywords', content: 'settings, page'},
        { property: 'og:site_name', content: 'Settings'},
        { name: 'description', content: 'Settings Seite vom Gewaechshaus'},
        { name: "twitter:description", content: "Settings Seite vom Gewaechshaus"},
        { itemprop: "description", content: "Settings Seite vom Gewaechshaus" },
        { property: "og:description", content: "Settings Seite vom Gewaechshaus"}
    ]
})
</script>

