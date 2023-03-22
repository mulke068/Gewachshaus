

<template>
    <div class=" text-white-50">
        <div class="text-xl">
            <div class="flex justify-center text-3xl ">Dashboard</div>
            <div class="grid grid-cols-2 gap-2">
                <div class="col-span-1 p-5 bg-gray-800 rounded-lg">
                    <div class="text-2xl">Total Users</div>
                    <div class="text-4xl">{{ items?.id }}</div>
                </div>
            </div>
        </div>
    </div>
</template>

<script setup>
const { data: data_items ,error, refresh, pending } = await useFetch('/api/data')
const items = data_items.value.data[0]
console.log(items.created_at)
</script>

<!-- 
const { data: data_items ,error, refresh, pending } = await useFetch('/api/data')
const data = data_items?._rawValue[0] -->

<!-- const {data: items } = useFetch("/api/data");
console.log(toRaw(items.value())); -->
