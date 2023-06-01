import { NuxtPage, NuxtLink, Settings } from '../../.nuxt/components';


<template>
    <div >
        <div class="container">
            <div class="flex justify-between ">
                <h1 class="p-5 text-3xl ">Dashboard</h1>
                <NuxtLink :to="`dashboard/settings`" >
                    <button class="btn btn-info">Settings</button>
                </NuxtLink>
            </div>
            <NuxtErrorBoundary>
                <Dashboard />
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
    layout: 'default'
})
useHead({
    title: 'Dashboard',
    meta: [
        { name: 'title', content: 'Dashboard'},
        { name: 'description', content: 'Dashboard Seite vom Gewaechshaus'},
        { name: 'keywords', content: 'dashboard, page'},
        { property: 'og:site_name', content: 'Dashboard'}
    ]
})
</script>


<!--NuxtErrorBoundary @error="error">
    <DashboardOverview />
    <template #error="{ error }">
        <div class="p-5 text-center text-gray-500 text-2l">
            Die Daten konnten nicht geladen werden.
            <br>
            {{ error.message }}
        </div>
    </template>
</NuxtErrorBoundary-->

                <!--div class="p-5 text-center text-gray-500 text-2l" 
                    v-for="item in items" v-bind:key="item._id">
                    {{ item }}
                </div-->

<!--
const { data: data_items ,error, refresh, pending } = await useFetch('/api/dataall')
const items = data_items._rawValue.data
console.log(items)
-->

<!--
const { data: data_items ,error, refresh, pending } = await useFetch('/api/data')
const items = data_items._rawValue.data[0]
console.log(items)
-->