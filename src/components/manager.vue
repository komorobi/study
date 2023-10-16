<template>
  <div class="manager">
    <div>
      <div class="manager-header">仓库列表</div>
    </div>
    <div class="manager-table">
      <table>
        <tr class="manger-tr">
          <th style="width: 10px;">编号</th>
          <th>名称</th>
          <th>管理员</th>
          <th>备注</th>
          <th>编辑</th>

        </tr>
        <tr v-for="(item, index) in Repository" :key="item['ID']" class="manger-tr">
          <td>{{ index }}</td>
          <td id="name">{{ item["name"] }}</td>
          <td id="owner">{{ item["uuid"] }} <button @click="changeAdmin(index)">调整管理员</button></td>
          <td id="remarks">{{ item["info"] }}</td>
          <td class="td-set">
            <button>
              <RouterLink to="/detail" @click="todetail(item['ID'])">物资详情</RouterLink>
            </button>
            <button @click="deleterepository(item['ID'])">删除仓库</button>
          </td>
        </tr>
      </table>
    </div>

    <div class="add-div">
      <button class="add-button">
        <RouterLink to="/addRepository">添加仓库</RouterLink>
      </button>
    </div>
  </div>
</template>

<script setup lang="ts">
//import { repository } from './list.json';
import { useRouter } from 'vue-router';
import Service from '@/api/config';
//import request from '../'
import { ref } from 'vue'
//import AddItem from '@/views/addItem.vue';

//获取仓库列表
let Repository: []
Service.get('/getRepository')
  .then(function (response) {

    Repository = response.data
  })

//删除仓库
function deleterepository(ID: string) {
  //Repository.splice(ID, 1)
  Service.post('/deleteRepository', ID)
    .then(function (response) {
      alert("删除成功！")
    })
  Service.get('/getRepository')
    .then(function (response) {
      Repository = response.data
    })
}
//改变uuid
function changeAdmin(index: number) {
  //Repository[index].uuid = ""

}


const router = useRouter();
//传参到详情页
function todetail(ID: string) {
  router.push({
    path: '/detail',
    query: {
      rid: ID
    }
  })
}



</script>

<style>
.manager {
  padding-top: 50px;
  margin-left: 200px;
}

/* .manager-tr {} */

.manager-header {
  padding-top: 90px;
  padding-bottom: 20px;
  text-align: center;
  font-size: 50px;
}

.manager-table {
  display: flex;
  justify-content: center;

}

td,
th {
  /* border: 1px solid black; */
  padding-left: 10px;
  height: 50px;
  line-height: 50px;
  width: 200px;
}

.td-set {
  width: 100px;
}

.manager-tr {
  background-color: #f2f2f2;
}

.add-div {}

.add-button {}
</style>
