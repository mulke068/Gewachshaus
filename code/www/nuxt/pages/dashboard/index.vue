

<template>
    <div class=" text-white-50">
        <div class="container">
            <div class="flex justify-center text-3xl">Dashboard</div>
            <NuxtErrorBoundary>
                <Dashboard />
                <template #error="{ error }">
                    <div class="p-5 text-center text-gray-500 text-2l">
                        Die Daten konnten nicht geladen werden.
                        <br>
                        {{ error.message }}
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