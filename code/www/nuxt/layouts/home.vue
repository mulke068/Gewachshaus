<template>
    <div>
        <BaseHeader />
        <slot />
    </div>
</template>

<style scoped>
BaseHeader {
    position: absolute;
}
slot {
    position: relative;
}
</style>
