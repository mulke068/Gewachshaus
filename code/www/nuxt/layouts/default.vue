import { NuxtLink } from '../.nuxt/components';

<template>
    <div>
        <header class="w-screen shadow-sm bg-minsk-900 h-28">
            <nav class="container flex justify-between p-4 mx-auto">
                <div class="h-auto">
                    <NuxtLink href="/"><img src="../assets/img/logo_1024x1024.png" alt="logo" class="object-fill w-20 h-20">
                    </NuxtLink>
                </div>
                <div class="text-xl  text-white-50 py-7">
                    <ul class="flex space-x-3 ">
                        <li>
                            <NuxtLink to="/">Home</NuxtLink>
                        </li>
                        <li>
                            <NuxtLink to="/dashboard">Dashboard</NuxtLink>
                        </li>
                    </ul>
                </div>
            </nav>
        </header>

        <!-- Output -->
        <article class="m-2 shadow-md  shadow-white-400">
            <div class="container p-4 mx-auto">
                <slot />
            </div>
        </article>
    </div>
</template>

<script>
</script>

<style>
.router-link-exact-active {
    color: #ff830d;
}
</style>