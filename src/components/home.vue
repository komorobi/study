<template>
  <div class="home">
    <div class="home-title">
      欢迎使用华南虎物资管理系统！
    </div>
    <div class="home-name">
      <div>
        <div class="person">亲爱的
          <div class="person-in">
            {{ person.name }}，
          </div>

        </div>
      </div>

      <div class="person">
        <div>
          你好，当前时间为：<div class="person-in">{{ currentdata }} {{ currenttime }}</div>

        </div>
      </div>


      <div>
        <div class="person">您的账号为：<div class="person-in">{{ person.id }}</div>
        </div>
      </div>
      <div>
        <div class="person">身份：<div class="person-in">{{ person.power }}</div>
        </div>
      </div>
    </div>

  </div>
</template>


<script setup lang="ts">
import { person } from './list.json'
let now = new Date();
let currentdata = now.toLocaleDateString();
let currenttime = now.toLocaleTimeString();
</script>


<style>
.home-title {
  padding-top: 50px;
  text-align: center;
  font-size: 50px;
}

.home-name {
  padding-top: 50px;
  /* text-align: center; */
  font-size: 25px;
  background-color: azure;
  padding: 50px;
}

.person {
  padding-left: 20%;
  text-align: left;
}

.person-in {
  color: rgb(61, 90, 90);
  display: inline;
}

.home {
  padding-top: 50px;
  margin-left: 200px;
  width: 100%;
}
</style>