<template>
    <div class="addItem">
        <div class="form-size">
            <div class="add-header">添加新物资！</div>
            <form action="" class="form-add">

                <label for="rnames" class="mark-name">新物资的名字：</label>
                <input type="text" name="rnames" class="forminput-size">

                <label for="onames" class="mark-name">物资的数量：</label>
                <input type="text" name="onames" class="forminput-size">

                <label for="onames" class="mark-name">入库时间：</label>
                <input type="date" class="forminput-size" name="myDate"
                    value="<%= new Date().toISOString().substr(0, 10) %>">

                <label for="onames" class="mark-name">物资的位置：</label>
                <input type="text" name="onames" class="forminput-size">

                <label for="remarks" class="mark-name">备注：</label>
                <textarea name="remarks" id="remarks" cols="30" rows="10" class="forminput-size"></textarea>

                <input type="submit" value="添加物资">

            </form>
        </div>
    </div>
</template>

<script setup lang="ts"></script>

<style>
.addItem {
    padding-top: 50px;
    margin-left: 300px;
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