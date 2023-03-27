

<template>
    <div class=" text-white-50">
        <div class="text-xl">
            <div class="flex justify-center text-3xl ">Dashboard</div>
            <div class="grid grid-cols-2 gap-2">
                <div class="col-span-1 p-5 bg-gray-800 rounded-lg">
                    <div class="text-2xl">{{ data }}</div>
                </div>
            </div>
        </div>
    </div>
</template>

<script setup>

const data = 'Hello World'

</script>

