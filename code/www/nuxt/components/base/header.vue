<template>
    <header class="shadow-sm bg-minsk-900 h-28">
        <nav class="container flex justify-between p-4 mx-auto">
            <div class="h-auto">
                <NuxtLink href="/"><img src="/img/logo-gewächshaus-lpem_1024x1024.png" alt="Gewächshaus Logo LPEM" class="object-fill w-20 h-20">
                </NuxtLink>
            </div>
            <div class="text-xl text-white-50 py-7">
                <ul class="flex space-x-3 ">
                    <li>
                        <NuxtLink to="/">Home</NuxtLink>
                    </li>
                    <li>
                        <NuxtLink to="/dashboard">Dashboard</NuxtLink>
                    </li>
                    <li>
                        <NuxtLink to="/sensor">Sensor</NuxtLink>
                    </li>
                </ul>
            </div>
        </nav>
    </header>
</template>

<style scoped>
.router-link-exact-active {
    color: #ff830d;
}
</style>
