<template>
  <div class="add">
    <div class="form-size">
      <div class="add-header">创建你的新仓库！</div>
      <form action="" class="form-add">

        <label for="rnames" class="mark-name" ref="rname">新仓库的名字：</label>
        <input type="text" id="rname" name="rnames" class="forminput-size">

        <label for="onames" class="mark-name" ref="rowner">创建者的名字：</label>
        <input type="text" id="rowner" name="onames" class="forminput-size">

        <label for="remarks" class="mark-name" ref="rremarks">备注：</label>
        <textarea name="remarks" id="remarks" cols="30" rows="10" class="forminput-size"></textarea>

        <input type="submit" value="创建仓库" @click="addRepository()">

      </form>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref } from 'vue';
import Service from '@/api/config';
const rname = ref<HTMLInputElement | null>(null);
const rowner = ref<HTMLElement | null>(null);
const rremarks = ref<HTMLElement | null>(null);

function addRepository() {

  Service.post('/addRepository', {
    name: rname.value,
    uuid: rowner.value,
    info: rremarks.value
  })
    .then(function (response) {

    })
    .catch(function (error) {
      console.log(error);
    })
}

</script>

<style>
.add {
  padding-top: 50px;
  margin-left: 350px;
}

.form-size {
  padding-top: 30px;

}

.add-header {
  font-size: 50px;
  text-align: center;
}

.form-add {
  display: flex;
  flex-wrap: wrap;
  flex-direction: column;
}

.mark-name {
  font-size: 20px;
  padding-top: 20px;
}



.forminput-size {
  font-size: 20px;
  width: 80%;
  padding: 12px 20px;
  margin: 8px 0;
  display: inline-block;
  border: 1px solid #ccc;
  border-radius: 4px;
  box-sizing: border-box;
}

input[type=submit] {
  width: 80%;
  background-color: #f2f2f2;
  color: black;
  padding: 14px 20px;
  margin: 8px 0;
  border: none;
  border-radius: 4px;
  cursor: pointer;
}

input[type=submit]:hover {
  background-color: #f2f2f2;
}
</style>